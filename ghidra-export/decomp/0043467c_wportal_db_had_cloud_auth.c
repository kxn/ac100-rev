// func wportal_db_had_cloud_auth @ 0043467c size=276

undefined4 wportal_db_had_cloud_auth(void)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  undefined4 uVar4;
  uint uVar5;
  
  iVar1 = wportal_get_mode();
  if (iVar1 == 1) {
    FUN_004082d0(wportal_rdt_mutex,0xffffffff);
    iVar1 = 0;
    do {
      iVar3 = rdt_list + iVar1;
      iVar1 = iVar1 + 0x16c;
      if (*(int *)(iVar3 + 0x15c) == 0x40) {
        uVar4 = 0;
        break;
      }
      uVar4 = 0xffffffff;
    } while (iVar1 != 0x16c000);
  }
  else {
    iVar1 = wportal_get_mode();
    if (iVar1 != 0) {
      return 0xffffffff;
    }
    uVar5 = 0;
    FUN_004082d0(wportal_rdt_mutex,0xffffffff);
    do {
      uVar2 = wserv_profile_get_max_wservice();
      if (uVar2 <= uVar5) {
        uVar4 = 0xffffffff;
        goto LAB_00434710;
      }
      iVar1 = *(int *)(wportal_wserv_node + uVar5 * 8 + 4);
      uVar5 = uVar5 + 1;
    } while ((iVar1 == 0) || (*(int *)(iVar1 + 0x15c) != 0x40));
    uVar4 = 0;
  }
LAB_00434710:
  FUN_00407f30(wportal_rdt_mutex);
  return uVar4;
}

