#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <libgen.h>
#include <libintl.h>
#include <locale.h>

#define _(STRING) gettext(STRING)

int main()
{
    setlocale(LC_ALL, "");
    bindtextdomain("guess", ".");
    textdomain("guess");

    char answer[6];
    int left = 0, right = 100, middle;

    while( right - left  > 1 )
    {
        middle = (left + right)/2;
        printf(_("Is Your number greater than %d? yes/no\n->"), middle);
		scanf("%s", answer);
        if (!strcmp(answer, _("yes"))){
            left = middle;
        } else if (!strcmp(answer, _("no"))){
            right = middle;
        } else{
			fprintf(stderr, _("Please, enter [yes/no]\n"));
		}
    }
    printf(_("Your number is %d\n"), right);
}

