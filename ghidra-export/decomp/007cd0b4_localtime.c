// func localtime @ 007cd0b4 size=1

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

tm * localtime(time_t *__timer)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}

