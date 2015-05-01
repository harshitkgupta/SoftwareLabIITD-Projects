#!/bin/bash
if [ -n "$1" -a "$1" = "-h" ]
then
	echo "usage: "`basename $0`" <folder-name> <extension-type> "
	exit
fi



directory=$1
suffix=$2
echo $1 $2 $#
browsefolders ()
{
    if [ -d "$directory" ]
    then     
        if  [[ "$directory" =~ [[:lower:]/]+ ]] 
        then
                 cd $directory 	
                 output=''	
                 for i in *; 
                 do    	
  	                 echo $i;
                        if     [ -f "$i" ]; 
                        then        
	                        extension=`echo "$i" | cut -d'.' -f2`
                                if [ $extension == $suffix ]; 
                                then
			                        pwd=`env|grep PWD|cut -d'=' -f2 `
        	                        output+="$PWD $i"
		
		                fi
                        elif [ -d "$i" ]
                        then    
                        if [[ "$i" =~ ^[[:lower:]/]+$ ]] 
                        then  
   	                    cd $i    
                                out=''
                                 for j in *; 
                                 do      
                                         echo $j;
                                         if     [ -f "$j" ]; 
                                        then        
                                                 extension=`echo "$j" | cut -d'.' -f2`
                                                 if [ $extension == $suffix ];
                                                then
                                                         pwd=`env|grep PWD|cut -d'=' -f2 `
                                                         out+="$PWD  $j"
    
                                                 fi

                                         fi
                                  done
                                  echo $out >match.txt
                        cd ..          
                        fi    
                        fi             
                done
                echo $output >match.txt
        fi
    fi
}
if [ $# == 2 ]
then 
        browsefolders  "$directory"
fi
