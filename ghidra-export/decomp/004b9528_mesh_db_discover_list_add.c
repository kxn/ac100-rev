// func mesh_db_discover_list_add @ 004b9528 size=1020

undefined4
mesh_db_discover_list_add
          (void *param_1,char *param_2,undefined1 *param_3,undefined1 param_4,undefined1 param_5,
          int param_6,short *param_7)

{
  short sVar1;
  void *pvVar2;
  void *pvVar3;
  int iVar4;
  undefined4 uVar5;
  void *__s;
  void *pvVar6;
  undefined *puVar7;
  
  if ((((param_1 == (void *)0x0) || (param_2 == (char *)0x0)) || (param_3 == (undefined1 *)0x0)) ||
     (param_7 == (short *)0x0)) {
    if (mesh_err_switch == '\0') {
      return 0xffffffff;
    }
    printf("[MESH_ERROR]%s()/%d Illegal input\n","mesh_db_discover_list_add",0x546);
    return 0xffffffff;
  }
  FUN_004082d0(DAT_00767eb4,0xffffffff);
  pvVar2 = (void *)FUN_00407fa0(DAT_00767f68,param_1);
  if (pvVar2 == (void *)0x0) {
    __s = (void *)FUN_00408450(0x68,0x54d);
    if (__s == (void *)0x0) {
      if (mesh_err_switch != '\0') {
        uVar5 = 0x550;
LAB_004b98b8:
        printf("[MESH_ERROR]%s()/%d Malloc failed\n","mesh_db_discover_list_add",uVar5);
      }
    }
    else {
      memset(__s,0,0x68);
      memcpy((void *)((int)__s + 0xc),param_1,6);
      *(undefined4 *)((int)__s + 100) = 0;
      FUN_0051ad88((int)__s + 0x58);
      pvVar2 = (void *)FUN_00408450(0x1c,0x558);
      if (pvVar2 == (void *)0x0) {
        if (mesh_err_switch != '\0') {
          printf("[MESH_ERROR]%s()/%d Malloc failed\n","mesh_db_discover_list_add",0x55b);
        }
      }
      else {
        memset(pvVar2,0,0x1c);
        memcpy((void *)((int)pvVar2 + 0xc),param_7,0xc);
        FUN_004086b0((int)__s + 0x58,pvVar2);
        iVar4 = FUN_00408380(DAT_00767f68,__s);
        if (iVar4 == 0) {
          puVar7 = &DAT_00767f5c;
          pvVar2 = __s;
          goto LAB_004b9830;
        }
        if (mesh_err_switch != '\0') {
          printf("[MESH_ERROR]%s()/%d Add discover entry to hash failed\n",
                 "mesh_db_discover_list_add",0x564);
        }
        FUN_00407df0(__s);
        __s = pvVar2;
      }
      FUN_00407df0(__s);
    }
LAB_004b9880:
    uVar5 = 0xffffffff;
    FUN_00407f30(DAT_00767eb4);
  }
  else {
    puVar7 = (undefined *)((int)pvVar2 + 0x58);
    pvVar6 = (void *)0x0;
    pvVar3 = (void *)FUN_004081b0(puVar7);
    __s = (void *)0x0;
    if (pvVar3 != (void *)0x0) {
      sVar1 = *(short *)((int)pvVar3 + 0xc);
      do {
        if ((__s == (void *)0x0) && (sVar1 == *param_7)) {
          iVar4 = _mesh_db_discover_link_info_compare(param_7,(int)pvVar3 + 0xc);
          __s = pvVar3;
          if (iVar4 != 1) goto LAB_004b9758;
joined_r0x004b95f8:
          if (pvVar6 != (void *)0x0) goto LAB_004b96e8;
        }
        else {
          if ((sVar1 != *param_7) &&
             (iVar4 = _mesh_db_discover_link_info_compare(param_7,(int)pvVar3 + 0xc), iVar4 == 1)) {
            pvVar6 = pvVar3;
          }
          if (__s != (void *)0x0) goto joined_r0x004b95f8;
        }
        pvVar3 = (void *)FUN_00408680(pvVar3);
        if (pvVar3 == (void *)0x0) break;
        sVar1 = *(short *)((int)pvVar3 + 0xc);
      } while( true );
    }
    if (__s == (void *)0x0) {
      __s = (void *)FUN_00408450(0x1c,0x58c);
      if (__s == (void *)0x0) {
        if (mesh_err_switch != '\0') {
          uVar5 = 0x58f;
          goto LAB_004b98b8;
        }
        goto LAB_004b9880;
      }
      memset(__s,0,0x1c);
      pvVar3 = (void *)((int)__s + 0xc);
      if (*(char *)(param_7 + 2) == '\x01') {
        for (iVar4 = FUN_004081b0(puVar7); pvVar3 = (void *)((int)__s + 0xc), iVar4 != 0;
            iVar4 = FUN_00408680(iVar4)) {
          if (*(char *)(iVar4 + 0x18) != '\0') {
            *(undefined1 *)(iVar4 + 0x18) = 0;
          }
        }
      }
    }
    else {
LAB_004b96e8:
      FUN_00408500(__s);
      pvVar3 = (void *)((int)__s + 0xc);
    }
    memcpy(pvVar3,param_7,0xc);
    if (pvVar6 == (void *)0x0) {
LAB_004b9830:
      FUN_004086b0(puVar7,__s);
    }
    else {
      FUN_00408170(pvVar6,__s);
    }
    if (param_6 == 0) {
      *(undefined4 *)((int)pvVar2 + 100) = 5;
    }
    strncpy((char *)((int)pvVar2 + 0x12),param_2,0x40);
    *(undefined1 *)((int)pvVar2 + 0x53) = *param_3;
    *(undefined1 *)((int)pvVar2 + 0x54) = param_3[1];
    *(undefined1 *)((int)pvVar2 + 0x55) = param_4;
    *(undefined1 *)((int)pvVar2 + 0x56) = param_5;
LAB_004b9758:
    uVar5 = 0;
    FUN_00407f30(DAT_00767eb4);
  }
  return uVar5;
}

