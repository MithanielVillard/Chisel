#ifndef EXCEPTION_H
#define EXCEPTION_H

namespace ctd 
{
	class Exception
	{
		public: 
			Exception() = default;
	    	Exception(const Exception&) = default;
	    	Exception& operator=(const Exception&) = default;
	    	Exception(Exception&&) = default;
	    	Exception& operator=(Exception&&) = default;
			virtual ~Exception() noexcept = default;
	
			virtual const char* what() noexcept {return ""; }
	};
	
	class BadAlloc : public Exception
	{
	public:
		BadAlloc() = default;
		~BadAlloc() override = default;
		const char* what() noexcept override { return "BadAlloc : allocation failed"; }
	};
}
#endif // !EXCEPTION_H
