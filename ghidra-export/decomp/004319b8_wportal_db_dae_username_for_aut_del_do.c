// func wportal_db_dae_username_for_aut_del_do @ 004319b8 size=708

undefined4 wportal_db_dae_username_for_aut_del_do(char *param_1,code *param_2,undefined4 param_3)

{
  size_t sVar1;
  void *pvVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  void *pvVar6;
  undefined4 uVar7;
  int iVar8;
  undefined1 auStack_220 [104];
  undefined1 auStack_1b8 [16];
  undefined1 auStack_1a8 [12];
  undefined1 auStack_19c [8];
  undefined1 auStack_194 [32];
  undefined1 auStack_174 [76];
  undefined1 local_128;
  
  uVar7 = 0xffffffff;
  memset(auStack_1a8,0,0x180);
  if (param_1 != (char *)0x0) {
    memset(auStack_220,0,0x74);
    FUN_0051ad88(auStack_1b8);
    sVar1 = strlen(param_1);
    memcpy(auStack_220,param_1,sVar1 + 1);
    pvVar2 = (void *)FUN_00408450(g_max_session * 0xc0,0x16f7);
    if (pvVar2 != (void *)0x0) {
      FUN_004082d0(wportal_aut_mutex,0xffffffff);
      iVar3 = FUN_00407fa0(username_hash_for_aut,auStack_220);
      if (iVar3 == 0) {
        uVar7 = 0xffffffff;
        FUN_00407f30(wportal_aut_mutex);
      }
      else {
        iVar8 = 0;
        iVar3 = FUN_004081b0(iVar3 + 0x68);
        while (iVar4 = iVar3, iVar4 != 0) {
          iVar3 = FUN_00408680(iVar4);
          if (((iVar4 + -0x11c != 0) && (*(char *)(iVar4 + -0x9b) == '\x01')) &&
             (iVar5 = (*param_2)(iVar4 + -0x11c,param_3), iVar5 == 0)) {
            iVar5 = iVar8 * 0xc0;
            iVar8 = iVar8 + 1;
            pvVar6 = (void *)((int)pvVar2 + iVar5);
            memcpy(pvVar6,(void *)(iVar4 + -0x110),6);
            memcpy((void *)((int)pvVar6 + 0x8d),(void *)(iVar4 + -0xe8),6);
            *(undefined1 *)((int)pvVar6 + 0x93) = *(undefined1 *)(iVar4 + -0x9c);
            *(undefined1 *)((int)pvVar6 + 0xbc) = *(undefined1 *)(iVar4 + -0x9b);
            memcpy((void *)((int)pvVar6 + 8),(void *)(iVar4 + -0x108),0x20);
            if (*(int *)(iVar4 + 0x2c) == -1) {
              iVar5 = *(int *)(iVar4 + -0x110);
            }
            else {
              FUN_00408060();
              iVar5 = *(int *)(iVar4 + -0x110);
            }
            if ((iVar5 == 0) && ((*(uint *)(iVar4 + -0x10c) & 0xffff0000) == 0)) {
              _wportal_db_aut_del_by_ip(iVar4 + -0xc4);
            }
            else {
              _wportal_db_aut_del(iVar4 + -0x110);
            }
          }
        }
        uVar7 = 0xffffffff;
        FUN_00407f30(wportal_aut_mutex);
        iVar3 = 0;
        pvVar6 = pvVar2;
        if (iVar8 != 0) {
          do {
            memcpy(auStack_19c,pvVar6,6);
            memcpy(auStack_174,(void *)((int)pvVar6 + 0x8d),6);
            local_128 = *(undefined1 *)((int)pvVar6 + 0x93);
            memcpy(auStack_194,(void *)((int)pvVar6 + 8),0x20);
            iVar4 = wportal_get_mode();
            if ((iVar4 == 1) ||
               (iVar4 = isStaAccess(*(undefined4 *)((int)pvVar6 + 8),pvVar6), iVar4 == 1)) {
              wportal_update_user_to_ap(auStack_1a8,1);
            }
            iVar3 = iVar3 + 1;
            pvVar6 = (void *)((int)pvVar6 + 0xc0);
          } while (iVar3 < iVar8);
          uVar7 = _wportal_db_del_aut_to_nginx(pvVar2,iVar8);
        }
      }
      FUN_00407df0(pvVar2);
    }
  }
  return uVar7;
}

