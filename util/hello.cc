#include <iostream>
#include <node_api.h>
// #include <raylib.h>  // Temporarily commented out

#define NAPI_CALL(env, call)                                      \
  do                                                              \
  {                                                               \
    napi_status status = (call);                                  \
    if (status != napi_ok)                                        \
    {                                                             \
      const napi_extended_error_info *error_info = NULL;          \
      napi_get_last_error_info((env), &error_info);               \
      bool is_pending;                                            \
      napi_is_exception_pending((env), &is_pending);              \
      if (!is_pending)                                            \
      {                                                           \
        const char *message = (error_info->error_message == NULL) \
                                  ? "empty error message"         \
                                  : error_info->error_message;    \
        napi_throw_error((env), NULL, message);                   \
        return NULL;                                              \
      }                                                           \
    }                                                             \
  } while (0)

napi_value Hello(napi_env env, napi_callback_info info) {
  size_t argc = 10; // max args
  napi_value args[10];
  
  NAPI_CALL(env, napi_get_cb_info(env, info, &argc, args, NULL, NULL));
  
  for (size_t i = 0; i < argc; ++i) {
    size_t str_len;
    NAPI_CALL(env, napi_get_value_string_utf8(env, args[i], NULL, 0, &str_len));
    
    char* str_value = new char[str_len + 1];
    NAPI_CALL(env, napi_get_value_string_utf8(env, args[i], str_value, str_len + 1, NULL));
    
    std::cout << str_value;
    delete[] str_value;
  }
  std::cout << std::endl;  // newline
  
  napi_value undefined;
  NAPI_CALL(env, napi_get_undefined(env, &undefined));
  return undefined;
}

napi_value InitRayUI(napi_env env, napi_callback_info info) {
  // Raylib code temporarily disabled to test compilation
  std::cout << "Raylib functionality temporarily disabled for testing" << std::endl;
  
  // Return a small result string
  napi_value result;
  NAPI_CALL(env, napi_create_string_utf8(env, "Raylib functionality disabled", NAPI_AUTO_LENGTH, &result));
  return result;
}

napi_value init(napi_env env, napi_value exports) {
  napi_value hello_fn, rayui_fn;
  
  NAPI_CALL(env, napi_create_function(env, nullptr, 0, Hello, nullptr, &hello_fn));
  NAPI_CALL(env, napi_set_named_property(env, exports, "hello", hello_fn));
  
  NAPI_CALL(env, napi_create_function(env, nullptr, 0, InitRayUI, nullptr, &rayui_fn));
  NAPI_CALL(env, napi_set_named_property(env, exports, "initRayUI", rayui_fn));
  
  return exports;
}

NAPI_MODULE(NODE_GYP_MODULE_NAME, init)
