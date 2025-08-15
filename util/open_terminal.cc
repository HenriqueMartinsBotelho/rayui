#include <node_api.h>
#include <stdlib.h>

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

napi_value OpenTerminal(napi_env env, napi_callback_info info)
{
  // Example using gnome-terminal, you can change it to xterm or konsole depending on your environment
  int result = system("gnome-terminal");

  napi_value result_value;
  NAPI_CALL(env, napi_create_int32(env, result, &result_value));

  return result_value;
}

napi_value init(napi_env env, napi_value exports)
{
  napi_value fn;
  NAPI_CALL(env, napi_create_function(env, nullptr, 0, OpenTerminal, nullptr, &fn));
  NAPI_CALL(env, napi_set_named_property(env, exports, "openTerminal", fn));
  return exports;
}

NAPI_MODULE(NODE_GYP_MODULE_NAME, init);
