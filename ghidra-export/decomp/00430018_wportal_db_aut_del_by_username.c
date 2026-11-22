// func wportal_db_aut_del_by_username @ 00430018 size=728

undefined4 wportal_db_aut_del_by_username(char *param_1,code *param_2,undefined4 param_3)

{
  size_t sVar1;
  void *pvVar2;
  int iVar3;
  int iVar4;
  void *pvVar5;
  undefined4 uVar6;
  int iVar7;
  int iVar8;
  undefined1 auStack_220 [104];
  undefined1 auStack_1b8 [16];
  undefined1 auStack_1a8 [12];
  undefined1 auStack_19c [8];
  undefined1 auStack_194 [32];
  undefined1 auStack_174 [76];
  undefined1 local_128;
  
  uVar6 = 0xffffffff;
  memset(auStack_1a8,0,0x180);
  if (param_1 != (char *)0x0) {
    memset(auStack_220,0,0x74);
    FUN_0051ad88(auStack_1b8);
    sVar1 = strlen(param_1);
    memcpy(auStack_220,param_1,sVar1 + 1);
    pvVar2 = (void *)FUN_00408450(g_max_session * 0xc0,0x121e);
    if (pvVar2 != (void *)0x0) {
      FUN_004082d0(wportal_aut_mutex,0xffffffff);
      iVar3 = FUN_00407fa0(username_hash_for_aut,auStack_220);
      if (iVar3 == 0) {
        FUN_00407f30(wportal_aut_mutex);
        FUN_00407df0(pvVar2);
      }
      else {
        iVar8 = 0;
        iVar3 = FUN_004081b0(iVar3 + 0x68);
        while (iVar4 = iVar3, iVar4 != 0) {
          iVar3 = FUN_00408680(iVar4);
          if ((iVar4 != 0x11c) && (iVar7 = iVar8 * 0xc0, *(char *)(iVar4 + -0x9b) != '\x01')) {
            iVar8 = iVar8 + 1;
            pvVar5 = (void *)((int)pvVar2 + iVar7);
            memcpy(pvVar5,(void *)(iVar4 + -0x110),6);
            memcpy((void *)((int)pvVar5 + 0x8d),(void *)(iVar4 + -0xe8),6);
            *(undefined1 *)((int)pvVar5 + 0x93) = *(undefined1 *)(iVar4 + -0x9c);
            *(undefined1 *)((int)pvVar5 + 0xbc) = *(undefined1 *)(iVar4 + -0x9b);
            memcpy((void *)((int)pvVar5 + 0x94),(void *)(iVar4 + -0xc4),0x28);
            memcpy((void *)((int)pvVar5 + 0x28),(void *)(iVar4 + -0x79),100);
            memcpy((void *)((int)pvVar5 + 8),(void *)(iVar4 + -0x108),0x20);
            if (*(int *)(iVar4 + 0x2c) == -1) {
              iVar7 = *(int *)(iVar4 + -0x110);
            }
            else {
              FUN_00408060();
              iVar7 = *(int *)(iVar4 + -0x110);
            }
            if ((iVar7 == 0) && ((*(uint *)(iVar4 + -0x10c) & 0xffff0000) == 0)) {
              _wportal_db_aut_del_by_ip(iVar4 + -0xc4);
            }
            else {
              _wportal_db_aut_del(iVar4 + -0x110);
            }
          }
        }
        FUN_00407f30(wportal_aut_mutex);
        pvVar5 = pvVar2;
        for (iVar3 = 0; iVar3 < iVar8; iVar3 = iVar3 + 1) {
          memcpy(auStack_19c,pvVar5,6);
          memcpy(auStack_174,(void *)((int)pvVar5 + 0x8d),6);
          local_128 = *(undefined1 *)((int)pvVar5 + 0x93);
          memcpy(auStack_194,(void *)((int)pvVar5 + 8),0x20);
          iVar4 = wportal_get_mode();
          if ((iVar4 == 1) ||
             ((iVar4 = wportal_get_mode(auStack_1a8), iVar4 == 0 &&
              (iVar4 = isStaAccess(*(undefined4 *)((int)pvVar5 + 8),pvVar5), iVar4 == 1)))) {
            wportal_update_user_to_ap(auStack_1a8,1);
          }
          if (param_2 != (code *)0x0) {
            (*param_2)(pvVar5,param_3);
          }
          pvVar5 = (void *)((int)pvVar5 + 0xc0);
        }
        uVar6 = 0;
        FUN_00407df0(pvVar2);
      }
    }
  }
  return uVar6;
}

