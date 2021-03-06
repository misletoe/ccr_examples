﻿//html(); funtion is HTML version of printf
//prototype : int html(const char *format_str,...); 

#if !defined(__CCR__)
#error "Not supported platform!"
#endif

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//For html() , ccrClearHTMLBuffer() and ccrFlushHTMLBuffer() function.
#include <ccr.h>

int main()
{
	srand(time(NULL));

	for (int i = 0; i < 10; i++)
	{
		//Clear html buffer.
		ccrClearHTMLBuffer();

		html("<html>\n");
		html("<head>\n");
		html("<meta name='viewport' "
			"content='width=320;"
			"maximum-scale=2.0;"
			"minimum-scale=0.2;"
			"initial-scale=1.0'/>");
		html("</head>\n");
		html("<body bgcolor=#%06lx>\n",
			(rand() % 255) | (rand() % 255) << 8 | (rand() % 255) << 16);
		html("<font size=7 color=#%06lx>Hello</font> ",
			(rand() % 255) | (rand() % 255) << 8 | (rand() % 255) << 16);
		html("<font size=7 color=#%06lx>World!!</font>\n",
			(rand() % 255) | (rand() % 255) << 8 | (rand() % 255) << 16);
		html("</body>\n");
		html("</html>\n");

		//Display html buffer.
		ccrFlushHTMLBuffer();

		printf("Press enter key...");
		char string[256];
		fgets(string, 256, stdin);
	}

	//Clear html view.
	ccrClearHTMLBuffer();
	ccrFlushHTMLBuffer();

	return 0;
}