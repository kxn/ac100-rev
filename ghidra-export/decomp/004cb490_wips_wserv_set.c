// func wips_wserv_set @ 004cb490 size=136

void wips_wserv_set(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  uint uVar2;
  int in_stack_0000012c;
  int in_stack_00000334;
  undefined1 local_208 [516];
  
  iVar1 = strncmp(&stack0x00000130,&stack0x00000338,0x32);
  if ((iVar1 != 0) || (in_stack_0000012c != in_stack_00000334)) {
    for (uVar2 = 0; uVar2 < 0x1f5; uVar2 = uVar2 + 1) {
      local_208[uVar2] = (&stack0x00000010)[uVar2];
    }
    wips_delete_whitelist_due_to_wserv(param_1,param_2,param_3,param_4);
  }
  return;
}

