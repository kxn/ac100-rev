// func udbgGetStack @ 005d3e6c size=236

undefined4 udbgGetStack(int param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 local_50;
  undefined4 local_4c;
  
  memset(&local_50,0,0x40);
  uVar1 = *(undefined4 *)(param_1 + 0x24);
  uVar2 = *(undefined4 *)(param_1 + 0x124);
  getExeAddrRange();
  puts("Stack information:\r");
  puts("\r\nVersion 1 [pc ra]: \r");
  local_50 = uVar1;
  local_4c = uVar2;
  resolveAddr(&local_50,2);
  puts("\r\nVersion 2 [not leaf]: \r");
  memset(&local_50,0,0x40);
  uVar1 = backtrace_mips32_notleaf(&local_50,0x10,param_1);
  resolveAddr(&local_50,uVar1);
  puts("\r\nVersion 3 [leaf]: \r");
  memset(&local_50,0,0x40);
  uVar1 = backtrace_mips32_leaf(&local_50,0x10,param_1);
  resolveAddr(&local_50,uVar1);
  return 0;
}

