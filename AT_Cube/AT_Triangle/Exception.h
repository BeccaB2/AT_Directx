#pragma once
#include <exception>
#include <string>

class Exception :public std::exception
{
public:
	Exception(int line, const char* file) noexcept;
	const char* what() const noexcept override; // Prints info about where error is thrown
	virtual const char* GetType() const noexcept;
	int GetLine() const noexcept;
	const std::string& GetFile() const noexcept;
	std::string GetOriginString() const noexcept;

private:
	int line; // Points to the line number
	std::string file; // File in which error occured

protected:
	mutable std::string whatBuffer;
};