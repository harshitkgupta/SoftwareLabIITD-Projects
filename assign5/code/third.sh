#!/bin/bash
if [ -n "$1" -a "$1" = "-h" ]
then
	echo "usage: "`basename $0`" <folder-name> <extension-type> "
	exit
fi



directory=$1
suffix=$2
#echo $1 $2 $#
browsefolders ()
{
    if [ -d "$directory" ]
    then     
        if  [[ "$directory" =~ ^[[:lower:]/]+$ ]] 
        then
                 cd $directory 	
                 output=''	
                 for i in *; 
                 do    	
  	                # echo $i;
                        if     [ -f "$i" ]; 
                        then        
	                        extension=`echo "$i" | cut -d'.' -f2`
                            filename=`echo "$i" | cut -d'.' -f1`
                                if [ $extension == $suffix ]; 
                                then
			                        pwd=`env|grep PWD|cut -d'=' -f2 `
        	                        output+="$PWD $i"
                                    if [ $extension = "c" ]
                                    then
                                        gcc   $i
                                        echo "....................executing $extension program............"
                                        ./a.out 
                                        rm a.out
                                    fi  
                                    if [ $extension = "sh" ]
                                    then
                                        echo "......................executing $extension program............"
                                        sudo chmod 777 $i
                                        ./$i 
                                    fi 
                                    if [ $extension = "gif" ]
                                    then
                                        echo "................converting  $i image to png format ............"
                                        src="$filename".gif
                                        dest="$filename".png
                                        convert  $src $dest
                                    fi                                     
		
		                fi
                        elif [ -d "$i" ]
                        then    
                        if [[ "$i" =~ ^[[:lower:]/]+$ ]] 
                        then  
   	                    cd $i    
                                out=''
                                 for j in *; 
                                 do      
                                        # echo $j;
                                         if     [ -f "$j" ]; 
                                        then        
                                                 extension=`echo "$j" | cut -d'.' -f2`
                                                 filename=`echo "$j" | cut -d'.' -f1`
                                                 if [ $extension == $suffix ];
                                                then
                                                         pwd=`env|grep PWD|cut -d'=' -f2 `
                                                         out+="$PWD  $j"
                                                         if [ $extension = "c" ]
                                                        then
                                                            gcc   $j
                                                            echo "....................executing $extension program............"
                                                             ./a.out 
                                                             rm a.out
                                                        fi  
                                                         if [ $extension = "sh" ]
                                                        then
                                                             echo "......................executing $extension program............"
                                                            sudo chmod 777 $j
                                                            ./$j
                                                        fi 
                                                        if [ $extension = "gif" ]
                                                        then
                                                             echo "................converting  $i image to jpg format ............"
                                                             src="$filename".gif
                                                            dest="$filename".png
                                                            convert  $src $dest
                                                         fi  
    
                                                 fi


                                         fi
                                  done
                                  if [ "$out" = '' ]
                                   then 
                                        out+="NO File matched the pattern" 
                                  fi      
                                  echo $out >match.txt
                        cd ..          
                        fi    
                        fi             
                done
                if [ "$output" = '' ]
                then 
                         output+="NO File matched the pattern" 
                 fi 
                echo $output >match.txt
        fi
    fi
}
if [ $# == 2 ]
then 
        browsefolders  "$directory"
fi
