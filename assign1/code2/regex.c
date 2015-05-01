#include"regex.h"

/* matchhere: search for regexp at beginning of text */
    int matchhere(char *regexp, char *text)
    {
        if (regexp[0] == '\0')
           return *text == '\0';
	
	/* star found then call another function */	
        if (regexp[0] == '*')
            return matchstar( regexp+1, text);
        
            
        if (*text!='\0' )
	{
		/* a ? either matches character or does not matches*/
		if (regexp[0]=='?' )
            		return matchhere(regexp+1,text)||matchhere(regexp+1, text+1);

		/* character in regular expression and text matches */ 
		if(regexp[0]==*text)
		return matchhere(regexp+1, text+1);
	}
        return 0;
    }

/* matchstar: search for c*regexp at beginning of text */
int matchstar(char *regexp, char *text)
    {
	char *t;
	/* find last pointer of string*/
	for (t = text; (*t != '\0' ); t++)
		;
        do {    
		/* a * matches zero or more instances */
            if (matchhere(regexp, t))
                return 1;
        } while (t--  >text );
        return 0;
    }
    
