char * mergeAlternately(char * word1, char * word2){
int n1=strlen(word1);
int n2=strlen(word2);
    char *w3=malloc((n1+n2+1)*sizeof(char));
    int i=0,j=0,k=0;
    while(word1[i]!='\0'|| word2[j]!='\0'){
        if(word1[i]=='\0')
        {
            w3[k++]=word2[j++];
        }
        else if(word2[j]=='\0'){
            w3[k++]=word1[i++];
        }
        else{
            w3[k++]=word1[i++];
            w3[k++]=word2[j++];
        }
    }
    w3[k]='\0';
    return w3;
}
