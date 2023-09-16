#include <string>

class ErrorLoggin {
	private:
		std::string textError;
	public:
		ErrorLoggin(const std::string& txt) {
			textError = txt;
		}

		std::string what() const { return textError; }
};

class ErrorPassword{
	private:
		std::string textError;
	public:
		ErrorPassword(const std::string& txt) {
			textError = txt;
		}

		std::string what() const { return textError; }
};

class ErrorAge {
	private:
		std::string textError;
	public:
		ErrorAge(const std::string& txt) {
			textError = txt;
		}
		std::string what() const { return textError; }
};

class ErrorNumber {
	private:
		std::string textError;
	public:
		ErrorNumber(const std::string& txt) {
			textError = txt;
		}
		std::string what() const { return textError; }
};