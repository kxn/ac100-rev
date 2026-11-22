// func uac_rdmngr_init_linked_modify @ 006305b8 size=1

undefined4 uac_rdmngr_init_linked_modify(void *param_1)

{
  uint uVar1;
  int iVar2;
  undefined4 uVar3;
  undefined1 auStack_100 [80];
  undefined1 auStack_b0 [84];
  undefined4 uStack_5c;
  undefined4 uStack_58;
  undefined4 uStack_54;
  undefined4 uStack_50;
  undefined1 auStack_4c [68];
  
  memset(&uStack_5c,0,0x54);
  memset(auStack_b0,0,0x54);
  memcpy(&uStack_5c,param_1,0x54);
  memcpy(auStack_b0,param_1,0x54);
  for (uVar1 = 0; uVar1 < 0x44; uVar1 = uVar1 + 1) {
    auStack_100[uVar1] = auStack_4c[uVar1];
  }
  uVar3 = 0;
  iVar2 = FUN_006270b4(uStack_5c,uStack_58,uStack_54,uStack_50);
  if (((iVar2 != 0) && (uVar3 = 0xffffffff, rdmngr_err_switch != 0)) &&
     (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
    printf("[RDMNGR_ERROR]%s()/%d _uac_rdmngr_linked_modify() failed.\n",
           "uac_rdmngr_init_linked_modify",0xcb4);
  }
  return uVar3;
}

