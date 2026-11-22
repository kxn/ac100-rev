// func wportal_db_dae_nas_port_for_aut_del_do @ 004316dc size=732

undefined4 wportal_db_dae_nas_port_for_aut_del_do(uint param_1,code *param_2,undefined4 param_3)

{
  int iVar1;
  uint uVar2;
  void *pvVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  undefined4 uVar7;
  void *pvVar8;
  undefined1 auStack_1a8 [12];
  undefined1 auStack_19c [8];
  undefined1 auStack_194 [32];
  undefined1 auStack_174 [76];
  undefined1 local_128;
  
  memset(auStack_1a8,0,0x180);
  iVar1 = wportal_get_mode();
  if (((iVar1 != 1) || (uVar7 = 0xffffffff, param_1 < 0x1000)) &&
     ((iVar1 = wportal_get_mode(), iVar1 != 0 ||
      ((uVar7 = 0xffffffff, -1 < (int)param_1 &&
       (uVar2 = wserv_profile_get_max_wservice(), param_1 < uVar2)))))) {
    uVar7 = 0xffffffff;
    pvVar3 = (void *)FUN_00408450(g_max_session * 0xc0,0x1672);
    if (pvVar3 != (void *)0x0) {
      FUN_004082d0(wportal_aut_mutex,0xffffffff);
      iVar4 = wportal_get_mode();
      iVar1 = vlan_list_array_for_aut;
      if (iVar4 != 1) {
        iVar1 = ssid_list_array_for_aut;
      }
      iVar4 = 0;
      iVar1 = FUN_004081b0(iVar1 + param_1 * 0xc);
      while (iVar5 = iVar1, iVar5 != 0) {
        iVar1 = FUN_00408680(iVar5);
        if (((iVar5 + -0x110 != 0) && (*(char *)(iVar5 + -0x8f) == '\x01')) &&
           (iVar6 = (*param_2)(iVar5 + -0x110,param_3), iVar6 == 0)) {
          iVar6 = iVar4 * 0xc0;
          iVar4 = iVar4 + 1;
          pvVar8 = (void *)((int)pvVar3 + iVar6);
          memcpy(pvVar8,(void *)(iVar5 + -0x104),6);
          memcpy((void *)((int)pvVar8 + 0x8d),(void *)(iVar5 + -0xdc),6);
          *(undefined1 *)((int)pvVar8 + 0x93) = *(undefined1 *)(iVar5 + -0x90);
          *(undefined1 *)((int)pvVar8 + 0xbc) = *(undefined1 *)(iVar5 + -0x8f);
          memcpy((void *)((int)pvVar8 + 8),(void *)(iVar5 + -0xfc),0x20);
          if (*(int *)(iVar5 + 0x38) == -1) {
            iVar6 = *(int *)(iVar5 + -0x104);
          }
          else {
            FUN_00408060();
            iVar6 = *(int *)(iVar5 + -0x104);
          }
          if ((iVar6 == 0) && ((*(uint *)(iVar5 + -0x100) & 0xffff0000) == 0)) {
            _wportal_db_aut_del_by_ip(iVar5 + -0xb8);
          }
          else {
            _wportal_db_aut_del(iVar5 + -0x104);
          }
        }
      }
      uVar7 = 0xffffffff;
      FUN_00407f30(wportal_aut_mutex);
      iVar1 = 0;
      pvVar8 = pvVar3;
      if (iVar4 != 0) {
        do {
          memcpy(auStack_19c,pvVar8,6);
          memcpy(auStack_174,(void *)((int)pvVar8 + 0x8d),6);
          local_128 = *(undefined1 *)((int)pvVar8 + 0x93);
          memcpy(auStack_194,(void *)((int)pvVar8 + 8),0x20);
          iVar5 = wportal_get_mode();
          if ((iVar5 == 1) ||
             (iVar5 = isStaAccess(*(undefined4 *)((int)pvVar8 + 8),pvVar8), iVar5 == 1)) {
            wportal_update_user_to_ap(auStack_1a8,1);
          }
          iVar1 = iVar1 + 1;
          pvVar8 = (void *)((int)pvVar8 + 0xc0);
        } while (iVar1 < iVar4);
        uVar7 = _wportal_db_del_aut_to_nginx(pvVar3,iVar4);
      }
      FUN_00407df0(pvVar3);
    }
  }
  return uVar7;
}

