// func wportal_db_aut_del_by_mode_id @ 00432abc size=888

undefined4 wportal_db_aut_del_by_mode_id(uint param_1,uint param_2,code *param_3,undefined4 param_4)

{
  int iVar1;
  uint uVar2;
  void *pvVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  undefined4 uVar7;
  void *pvVar8;
  undefined1 auStack_320 [356];
  int local_1bc;
  undefined1 auStack_1b0 [12];
  undefined1 auStack_1a4 [8];
  undefined4 local_19c [8];
  undefined1 auStack_17c [76];
  undefined1 local_130;
  uint local_30;
  
  local_30 = param_2 & 0xff;
  memset(auStack_1b0,0,0x180);
  memset(auStack_320,0,0x16c);
  iVar1 = wportal_get_mode();
  if (((iVar1 != 1) || (uVar7 = 0xffffffff, param_1 < 0x1000)) &&
     ((iVar1 = wportal_get_mode(), iVar1 != 0 ||
      ((uVar7 = 0xffffffff, -1 < (int)param_1 &&
       (uVar2 = wserv_profile_get_max_wservice(), param_1 < uVar2)))))) {
    uVar7 = 0xffffffff;
    pvVar3 = (void *)FUN_00408450(g_max_session * 0xc0,0x118f);
    if (pvVar3 != (void *)0x0) {
      FUN_004082d0(wportal_aut_mutex,0xffffffff);
      iVar4 = wportal_get_mode();
      iVar1 = vlan_list_array_for_aut;
      if ((iVar4 == 1) || (iVar4 = wportal_get_mode(), iVar1 = ssid_list_array_for_aut, iVar4 == 0))
      {
        iVar4 = 0;
        iVar1 = FUN_004081b0(iVar1 + param_1 * 0xc);
        while (iVar5 = iVar1, iVar5 != 0) {
          iVar1 = FUN_00408680(iVar5);
          if ((iVar5 != 0x110) && ((local_30 & *(byte *)(iVar5 + -0x90)) != 0)) {
            pvVar8 = (void *)((int)pvVar3 + iVar4 * 0xc0);
            memcpy(pvVar8,(void *)(iVar5 + -0x104),6);
            memcpy((void *)((int)pvVar8 + 0x8d),(void *)(iVar5 + -0xdc),6);
            *(undefined1 *)((int)pvVar8 + 0x93) = *(undefined1 *)(iVar5 + -0x90);
            *(undefined1 *)((int)pvVar8 + 0xbc) = *(undefined1 *)(iVar5 + -0x8f);
            memcpy((void *)((int)pvVar8 + 0x28),(void *)(iVar5 + -0x6d),100);
            memcpy((void *)((int)pvVar8 + 0x94),(void *)(iVar5 + -0xb8),0x28);
            iVar6 = wportal_get_mode();
            if (iVar6 == 1) {
              *(undefined4 *)((int)pvVar8 + 8) = *(undefined4 *)(iVar5 + -0xfc);
LAB_00432d78:
              iVar6 = *(int *)(iVar5 + 0x38);
            }
            else {
              iVar6 = wportal_get_mode();
              if (iVar6 == 0) {
                *(uint *)((int)pvVar8 + 8) = param_1;
                goto LAB_00432d78;
              }
              iVar6 = *(int *)(iVar5 + 0x38);
            }
            iVar4 = iVar4 + 1;
            if (iVar6 != -1) {
              FUN_00408060();
            }
            if ((*(int *)(iVar5 + -0x104) == 0) && ((*(uint *)(iVar5 + -0x100) & 0xffff0000) == 0))
            {
              _wportal_db_aut_del_by_ip(iVar5 + -0xb8);
            }
            else {
              _wportal_db_aut_del(iVar5 + -0x104);
            }
          }
        }
        FUN_00407f30(wportal_aut_mutex);
        pvVar8 = pvVar3;
        for (iVar1 = 0; iVar1 < iVar4; iVar1 = iVar1 + 1) {
          memcpy(local_19c,(void *)((int)pvVar8 + 8),0x20);
          memcpy(auStack_1a4,pvVar8,6);
          memcpy(auStack_17c,(void *)((int)pvVar8 + 0x8d),6);
          local_130 = *(undefined1 *)((int)pvVar8 + 0x93);
          memset(auStack_320,0,0x16c);
          iVar5 = wportal_get_mode();
          if (iVar5 == 1) {
            wportal_db_rdt_get_by_vlan(local_19c[0],auStack_320);
          }
          else {
            iVar5 = wportal_get_mode();
            if (iVar5 == 0) {
              wportal_db_ssid_rdt_get(local_19c[0],auStack_320);
            }
          }
          if (local_1bc == 0) {
            wportal_update_user_to_ap(auStack_1b0,1);
          }
          if (param_3 != (code *)0x0) {
            (*param_3)(pvVar8,param_4);
          }
          pvVar8 = (void *)((int)pvVar8 + 0xc0);
        }
      }
      else {
        FUN_00407f30(wportal_aut_mutex);
      }
      uVar7 = 0;
      FUN_00407df0(pvVar3);
    }
  }
  return uVar7;
}

