// func wportal_db_dae_calling_station_for_aut_del_do @ 00433a5c size=672

undefined4
wportal_db_dae_calling_station_for_aut_del_do(int param_1,code *param_2,undefined4 param_3)

{
  void *pvVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  int iVar6;
  void *pvVar7;
  int iVar8;
  undefined1 auStack_1a8 [12];
  undefined1 auStack_19c [8];
  undefined1 auStack_194 [32];
  undefined1 auStack_174 [76];
  undefined1 local_128;
  
  uVar5 = 0xffffffff;
  memset(auStack_1a8,0,0x180);
  if ((param_1 != 0) &&
     (pvVar1 = (void *)FUN_00408450(g_max_session * 0xc0,0x177a), pvVar1 != (void *)0x0)) {
    FUN_004082d0(wportal_aut_mutex,0xffffffff);
    iVar2 = FUN_00407fa0(dm_calling_station_hash,param_1);
    if (iVar2 == 0) {
      uVar5 = 0xffffffff;
      FUN_00407f30(wportal_aut_mutex);
    }
    else {
      iVar6 = 0;
      iVar2 = FUN_004081b0(iVar2 + 8);
      while (iVar3 = iVar2, iVar3 != 0) {
        iVar8 = iVar3 + -0x128;
        iVar2 = FUN_00408680(iVar3);
        if (((iVar8 != 0) && (*(char *)(iVar3 + -0xa7) == '\x01')) &&
           (iVar4 = (*param_2)(iVar8,param_3), iVar4 == 0)) {
          iVar4 = iVar6 * 0xc0;
          iVar6 = iVar6 + 1;
          pvVar7 = (void *)((int)pvVar1 + iVar4);
          memcpy(pvVar7,(void *)(iVar3 + -0x11c),6);
          memcpy((void *)((int)pvVar7 + 0x8d),(void *)(iVar3 + -0xf4),6);
          *(undefined1 *)((int)pvVar7 + 0x93) = *(undefined1 *)(iVar3 + -0xa8);
          *(undefined1 *)((int)pvVar7 + 0xbc) = *(undefined1 *)(iVar3 + -0xa8);
          memcpy((void *)((int)pvVar7 + 8),(void *)(iVar3 + -0x114),0x20);
          if (*(int *)(iVar3 + 0x20) == -1) {
            iVar4 = *(int *)(iVar3 + -0x11c);
          }
          else {
            FUN_00408060();
            iVar4 = *(int *)(iVar3 + -0x11c);
          }
          if ((iVar4 == 0) && ((*(uint *)(iVar3 + -0x118) & 0xffff0000) == 0)) {
            _wportal_db_aut_del_by_ip(iVar3 + -0xd0);
          }
          else {
            _wportal_db_aut_del(iVar3 + -0x11c);
          }
          wportal_db_foreach_event_list(1,iVar8,0);
        }
      }
      uVar5 = 0xffffffff;
      FUN_00407f30(wportal_aut_mutex);
      iVar2 = 0;
      pvVar7 = pvVar1;
      if (iVar6 != 0) {
        do {
          memcpy(auStack_19c,pvVar7,6);
          memcpy(auStack_174,(void *)((int)pvVar7 + 0x8d),6);
          local_128 = *(undefined1 *)((int)pvVar7 + 0x93);
          memcpy(auStack_194,(void *)((int)pvVar7 + 8),0x20);
          iVar3 = wportal_get_mode();
          if ((iVar3 == 1) ||
             (iVar3 = isStaAccess(*(undefined4 *)((int)pvVar7 + 8),pvVar7), iVar3 == 1)) {
            wportal_update_user_to_ap(auStack_1a8,1);
          }
          iVar2 = iVar2 + 1;
          pvVar7 = (void *)((int)pvVar7 + 0xc0);
        } while (iVar2 < iVar6);
        uVar5 = _wportal_db_del_aut_to_nginx(pvVar1,iVar6);
      }
    }
    FUN_00407df0(pvVar1);
  }
  return uVar5;
}

