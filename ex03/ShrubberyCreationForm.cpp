#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137), _target("noname"){}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm", 145, 137), _target(target){}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &copy) : AForm(copy.getName(), copy.getGradeToSign(), copy.getGradeToExecute()), _target(copy.getTarget()){}

ShrubberyCreationForm::~ShrubberyCreationForm(){}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm &rhs)
{
	if (this != &rhs)
	{
		this->_target = rhs.getTarget();
	}
	return *this;
}

std::string ShrubberyCreationForm::getTarget() const
{
	return this->_target;
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	std::string filename = this->getTarget() + "_shrubbery";
	if (!this->getSigned())
		throw AForm::FormNotSigned();
	else if (executor.getGrade() > this->getGradeToExecute())
		throw AForm::GradeTooLowException();
	else
	{
		std::fstream file;
		file.open(filename.c_str(), std::ios::out);
		if (!file.is_open())
			return (std::cerr << "Error: file not found or insufficient permissions to read the file." << std::endl, void());
		else
		{
			file << "                                                         .\n" <<
"                                              .         ;  \n" <<
"                 .              .              ;%     ;;   \n" <<
"                   ,           ,                :;%  %;   \n" <<
"                    :         ;                   :;%;'     .,   \n" <<
"           ,.        %;     %;            ;        %;'    ,;\n" <<
"             ;       ;%;  %%;        ,     %;    ;%;    ,%'\n" <<
"              %;       %;%;      ,  ;       %;  ;%;   ,%;' \n" <<
"               ;%;      %;        ;%;        % ;%;  ,%;'\n" <<
"                `%;.     ;%;     %;'         `;%%;.%;'\n" <<
"                 `:;%.    ;%%. %@;        %; ;@%;%'\n" <<
"                    `:%;.  :;bd%;          %;@%;'\n" <<
"                      `@%:.  :;%.         ;@@%;'   \n" <<
"                        `@%.  `;@%.      ;@@%;         \n" <<
"                          `@%%. `@%%    ;@@%;        \n" <<
"                            ;@%. :@%%  %@@%;       \n" <<
"                              %@bd%%%bd%%:;     \n" <<
"                                #@%%%%%:;;\n" <<
"                                %@@%%%::;\n" <<
"                                %@@@%(o);  . '         \n" <<
"                                %@@@o%;:(.,'         \n" <<
"                            `.. %@@@o%::;         \n" <<
"                               `)@@@o%::;         \n" <<
"                                %@@(o)::;        \n" <<
"                               .%@@@@%::;         \n" <<
"                               ;%@@@@%::;.          \n" <<
"                              ;%@@@@%%:;;;. \n" <<
"                          ...;%@@@@@%%:;;;;,..    \n";
			file.close();
		}
	}
}

std::ostream& operator<<(std::ostream &out, const ShrubberyCreationForm &rhs)
{
	out << rhs.getName() << ", ShrubberyCreationForm grade to sign " << rhs.getGradeToSign() << ", grade to execute " << rhs.getGradeToExecute() << " " << (rhs.getSigned() ? "is signed":"is not signed") << ".";
	return out;
}