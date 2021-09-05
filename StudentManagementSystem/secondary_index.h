#pragma once
#ifndef secondary_index_H
#define secondary_index_H
#include<string>
#include <utility>

class secondary_index
{
private:
	std::string student_name_, student_usn_;
public:
	secondary_index();
	std::string get_student_name() const;
	std::string get_student_usn() const;
	void set_student_name(std::string);
	void set_student_usn(std::string);
};

inline secondary_index::secondary_index()
{
	student_name_ = "";
	student_usn_ = "";
}

inline std::string secondary_index::get_student_name() const
{
	return student_name_;
}
inline std::string secondary_index::get_student_usn() const
{
	return student_usn_;
}

inline void secondary_index::set_student_name(std::string p_student_name)
{
	student_name_ = std::move(p_student_name);
}

inline void secondary_index::set_student_usn(std::string p_student_usn)
{
	student_usn_ = std::move(p_student_usn);
}

#endif