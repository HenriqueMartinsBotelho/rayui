all: bundle.js native.js

bundle.js: browser.js App.js
			../node_modules/.bin/browserify browser.js -o bundle.js


%.js: %.jsx
	../node_modules/.bin/babel $< --presets @babel/preset-react -o $@
