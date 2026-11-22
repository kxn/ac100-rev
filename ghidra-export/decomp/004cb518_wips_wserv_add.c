// func wips_wserv_add @ 004cb518 size=100

void wips_wserv_add(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  uint uVar1;
  undefined1 local_208 [516];
  
  for (uVar1 = 0; uVar1 < 0x1f5; uVar1 = uVar1 + 1) {
    local_208[uVar1] = (&stack0x00000010)[uVar1];
  }
  wips_delete_whitelist_due_to_wserv(param_1,param_2,param_3,param_4);
  return;
}

