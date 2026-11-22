// func cw_idle_timeout_dump @ 0057637c size=132

undefined4 cw_idle_timeout_dump(int param_1)

{
  undefined4 *puVar1;
  
  puVar1 = *(undefined4 **)(param_1 + 0x10);
  printf("\t\tType: (t=%d,l=%d) Idle Timeout \r\n",(uint)*(ushort *)(param_1 + 0xc),
         (uint)*(ushort *)(param_1 + 0xe));
  printf("\t\t\tType: Type: Idle Timeout (%d) \r\n",(uint)*(ushort *)(param_1 + 0xc));
  printf("\t\t\tLength: %d \r\n",(uint)*(ushort *)(param_1 + 0xe));
  printf("\t\t\tValue: %08x\r\n",*puVar1);
  printf("\t\t\tIdle Timeout (Sec): %d \r\n",*puVar1);
  return 0;
}

