

#!/bin/bash
prompt='Please enter what system information you would like to know (Enter number)'
options=("Current logged user" "Your shell directory" "Home directory" "OS name and version" "Current working directory" "Number of users logged in" "Show all available shells in your system" "Hard disk information" "CPU information" "Memory information" "File system information" "Currently running process")
echo $prompt
select opt in "${options[@]}" Quit
do
	case $opt in
		"Current logged user")
			whoami
			;;
		"Your shell directory")
			ls
			;;
		"Home directory")
			cd
			ls
			;;
		"OS name and version")
			cat /proc/version
			;;
		"Current working directory")
			pwd
			;;
		"Number of users logged in")
			users
			;;
		"Show all available shells in your system")
			cat /etc/shells
			;;
		"Hard disk information")
			df
			;;
		"CPU information")
			head cat /proc/cpuinfo
			;;
		"Memory information")
			cat /proc/meminfo
			;;
		"File system information")
			 df -Th
			;;
		"Currently running process")
			ps -aux
			;;
		"Quit")
			echo "Quit"
			break
			;;
		*) echo "invalid option $REPLY"
	esac
done	
