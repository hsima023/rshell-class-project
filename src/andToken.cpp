#include "andToken.h"
#include "Executor.h"

void andToken::logic(char **argv){
	Executor ex(argv);
       	for (int i = 0;argv[i] != null;  i++){
            if(argv[i] == "&&" && argv[0] != "&&" ){
                   if (ex.execute(argv[i - 1]){
                            ex.execute(argv[i + 1]);
                   }
                   else {
                          exit(1);
                   }
             }
         }
}
};

