// func __start @ 0040b1a0 size=80

void processEntry __start(undefined4 param_1,undefined4 param_2)

{
  undefined1 auStack_20 [16];
  code *local_10;
  undefined4 local_c;
  undefined1 *local_8;
  
  local_8 = auStack_20;
  local_10 = _fini;
  local_c = param_1;
  __uClibc_main(main,param_2,&stack0x00000004,_init);
  do {
                    /* WARNING: Do nothing block with infinite loop */
  } while( true );
}

