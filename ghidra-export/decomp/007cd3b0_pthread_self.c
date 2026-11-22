// func pthread_self @ 007cd3b0 size=1

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

pthread_t pthread_self(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}

