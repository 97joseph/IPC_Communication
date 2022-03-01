  #include <stdio.h>
  #include <string.h>
  #include <stdlib.h>
  #define ASYN 22
  #define ASYN2 22
  
  int count1s(char* bin_arr){
  	int i,c=0;
  	for(i=0;i<8;i++){
  		if(bin_arr[i]=='1'){
  			c++;
		  }
	  }
  	return c;
  }
  
  int chose_bitpos(int lower,int upper){
  	int num;
  	num=(rand()%(upper-lower+1))+lower;
  	return num;
  }
  int * getRandom(int lower, int upper,int times)
	{
    int *p= malloc(sizeof(times)); 
        int i,j=0;
    for (i = 0; i < times; i++) {
        int num = (rand() %(upper - lower + 1)) + lower;
       // printf("%d ", num);
        p[j++]=num;
    }
    return p;
    
	}
  
  int main()
  {
  	FILE *fp,*fp2,*fp3;
  	int word_count=0;
  	char word_buff[1000];
  		fp3 = fopen("newinput.inpf","r");
  		
		  if (fp3 == NULL){
			printf("no file found\n");	  
      		return 0;
    		}
    		 while( fscanf(fp3, "%s", word_buff) != EOF ){
    		 	word_count++;
			 }
    	fclose(fp3);
    	
    	//error module
    	int createError=0,*changedPos,noofbits=0;
    	int sze=word_count+1;
    	int letter_poss[sze];
    	int modify_bits[sze];
    	memset(modify_bits,0,sze);
    	  printf(" Press 1 to create error in transmission\n Press 0 if you don't want to create error :");
	   printf("\n");
	  scanf("%d",&createError);
	  
	  if(createError==1){
	  	printf("How many bits to modify: \n");
	  	printf("\n");
	  	scanf("%d",&noofbits);
	  //get random positions to change bits	
		srand(time(0));
	  	changedPos=getRandom(0,word_count,noofbits);
	  	int i;
		  for(i=0;i<noofbits;i++){
	//	printf("random pos are : %d\t",changedPos[i]);
		  }
		  
		}
    	
    	
    	
    //printf("No of words: %d\n",word_count);
    	
	  fp = fopen("newinput.inpf","r");
  		
		  if (fp == NULL){
			printf("no file found\n");	  
      		return 0;
    		}
    		
    	fp2=fopen("binary_file.binf","wb");
	
		if(!fp2){
			printf("Unable to open file \n");
			return 0;
		}
    		
    	char temp[50];
    	memset(temp,0,50);
    	int i;
    	int cnt_chkr=0;
    	   while( fscanf(fp, "%s", temp) != EOF )
        	{
            //one word
            //now do binary stuff
            char whole_word_bin[1000]={0};
            memset(whole_word_bin,0,1000);
            
            //ASYN values to binary here
            char asy_bin[8]={0};
            char asy_string[8]={0};
             memset(asy_bin,0,8);
            int k;
            	for(k=7;k>=0;k--)
				{
            		char letter=ASYN;
            		asy_bin[k]= ( letter >> k ) & 1 ? '1' : '0';
            		strncat(asy_string,&asy_bin[k],1);
				}
				
				//TWO ASYN VALUES CONVERTED
            strcat(whole_word_bin,asy_string);
            strcat(whole_word_bin,asy_string);
            //NOW LENGTH
            int l= strlen(temp);
            char len_bin[8]={0};
            char len_strring[8]={0};
            int h;
            	for(h=7;h>=0;h--)
				{
            		char letter=l;
            		len_bin[h]= ( letter >> h ) & 1 ? '1' : '0';
            		strncat(len_strring,&len_bin[h],1);
				}
			if(count1s(len_strring)%2==0){
				len_strring[0]='1';
			}
			
            //concat length binary
            strcat(whole_word_bin,len_strring);
            
            char bin_arr[8];
            int j,charpos=-1;
            	int er;
            
            for(er=0;er<noofbits;er++)
			{	
				if(cnt_chkr==changedPos[er]){
				
				if(strlen(temp)!=1){	
				charpos=chose_bitpos(0,strlen(temp)-1);
			
				}
				else{
						charpos=0;
				}
				}
				
			}
            int chtr_ctr=0;
            //word conversion starts
            for(i=0;i<strlen(temp);i++)
			{
//            	memset(bin_arr,0,8);
            	char strring[8]={0};
			
				
				//CHARACTER CONVERTED TO BINARY
				for(j=7;j>=0;j--)
				{
            		char letter=temp[i];
            	
            		bin_arr[j]= ( letter >> j ) & 1 ? '1' : '0';	
            	
            		strncat(strring,&bin_arr[j],1);
				}
				for(j=0;j<strlen(strring);j++){
				//	printf("%c",strring[j]);
				}
				//parity check
				int get_1_count=count1s(strring);
				//add parity if even
				if(get_1_count%2==0){
			
					strring[0]='1';
				}
				
				//do error modification
				
					if(chtr_ctr==charpos){
				
						int bpos=chose_bitpos(1,7);
				
						if(strring[bpos]=='1'){
						printf("Error introduced at %s word %c character %d pos from 1 to 0 \n",temp,temp[i],bpos);
						strring[bpos]='0';
					
							}
						else if(strring[bpos]=='0'){
						printf("Error introduced at %s word %c character %d pos from 0 to 1 \n",temp,temp[i],bpos);
						strring[bpos]='1';
						
					}
					}
				
				//character conversion end --------
				//one character binary is strring
				strcat(whole_word_bin,strring);
				
			
            	chtr_ctr++;
			}
			//---word conversion end
			//whole word here in binary
		
			fprintf(fp2,"%s ",whole_word_bin);

            cnt_chkr++;
//            break;
        	}
        	//--whole file conversion end
        	printf("\n---------encoded to binary check binary_file.binf file--------\n");
        	
  	fclose(fp);
  	fclose(fp2);
  	return 0;
  }
