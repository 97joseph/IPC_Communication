  #include <stdio.h>
  #include <string.h>
  #include <stdlib.h>
  
  
   int checkIfparity(char* bin_arr){
  	
  	if(bin_arr[0]=='1'){
  		return 1;
	  }
  	return 0;
  }
  
  
  int main(){
  	FILE *fp,*fp2,*mfp,*dfp;
  	 fp= fopen("binary_file.binf","r");
  		if (fp == NULL)
      	{
	  		printf("Unable to find file\n");
	  	return 0;
		}
		  	fp2=fopen("output_ascii.outf","w");
  	
  			if(!fp2){
  			printf("Unale to open output_ascii.outf file\n");
  			return 0;
	  		}
		
		char temp[1000]={0};
		
		 while( fscanf(fp, "%s", temp) != EOF )
        	{
        	//change binary to character
        	int i;
        	char final_word[1000]={0};
        	for(i=24;i<strlen(temp);i=i+8)
			{
        		int j,k=0,l=0;
        		char bin_str[8]={0};
        		char ch;
        		for(j=i;j<i+8;j++){
  				//store 8 bits to a character string
  				bin_str[k++]=temp[j];
				}
				bin_str[8]='\0';
				
				int isParity=checkIfparity(bin_str);
					if(isParity==1)
					{
						bin_str[0]='0';
					}
					
				ch=0;
				for(l=0;l<8;l++)
				{
					ch |=(bin_str[l]&1)<<(7-l);
				}
				strncat(final_word,&ch,1);		
			}
		
			fprintf(fp2,"%s ",final_word);
        	
        	memset(temp,0,1000);
//        	break;
			}
  	
  	
  	printf("\n");
  	fclose(fp);
  	fclose(fp2);
  	mfp= fopen("newinput.inpf","r");
  		
		  if (mfp == NULL){
			printf("no file found\n");	  
      		return 0;
    		}
    		
  	dfp=fopen("output_ascii.outf","r");
  	
  			if(!dfp){
  			printf("Unale to open output_ascii.outf file\n");
  			return 0;
	  		}
  	//error debugger
  	printf("\n--------Transmission decoded and stored in output_ascii.outf file----------\n");
  	char main_str[1000]={0};
  	char debug_str[1000]={0};
  	int flag=0;
  	
  	for(;fscanf(mfp, "%s", main_str) != EOF,fscanf(dfp,"%s",debug_str)!=EOF;)
	  {
  		if(strcmp(main_str,debug_str)==0){
		  }
		  else{
		  	printf("Not same: %s %s \n",main_str,debug_str);
		  	flag=1;
		  }
memset(main_str,0, 1000);
memset(debug_str,0,1000);
  		
	  }
	  fclose(mfp);
	  fclose(dfp);
	  if(flag==1){
	  	printf("\n--------Are the errors from transmission----------\n");
	  }
  	return 0;
  }
