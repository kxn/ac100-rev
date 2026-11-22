// func wportal_db_aut_del_all @ 004302f0 size=460

undefined4 wportal_db_aut_del_all(code *param_1,undefined4 param_2)

{
  void *pvVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  void *pvVar6;
  int iVar7;
  
  pvVar1 = (void *)FUN_00408450(g_max_session * 0xc0,0x128f);
  uVar2 = 0xffffffff;
  if (pvVar1 != (void *)0x0) {
    iVar7 = 0;
    FUN_004082d0(wportal_aut_mutex,0xffffffff);
    iVar3 = FUN_004081b0(aut_list);
    pvVar6 = pvVar1;
    while (iVar3 != 0) {
      iVar4 = FUN_00408680(iVar3);
      memcpy(pvVar6,(void *)(iVar3 + 0xc),6);
      iVar7 = iVar7 + 1;
      memcpy((void *)((int)pvVar6 + 0x8d),(void *)(iVar3 + 0x34),6);
      *(undefined1 *)((int)pvVar6 + 0x93) = *(undefined1 *)(iVar3 + 0x80);
      *(undefined1 *)((int)pvVar6 + 0xbc) = *(undefined1 *)(iVar3 + 0x80);
      memcpy((void *)((int)pvVar6 + 8),(void *)(iVar3 + 0x14),0x20);
      strncpy((char *)((int)pvVar6 + 0x28),(char *)(iVar3 + 0xa3),100);
      strncpy((char *)((int)pvVar6 + 0x94),(char *)(iVar3 + 0x58),0x28);
      if (*(int *)(iVar3 + 0x148) == -1) {
        iVar5 = *(int *)(iVar3 + 0xc);
      }
      else {
        FUN_00408060();
        iVar5 = *(int *)(iVar3 + 0xc);
      }
      if ((iVar5 == 0) && ((*(uint *)(iVar3 + 0x10) & 0xffff0000) == 0)) {
        _wportal_db_aut_del_by_ip(iVar3 + 0x58);
      }
      else {
        _wportal_db_aut_del(iVar3 + 0xc);
      }
      pvVar6 = (void *)((int)pvVar6 + 0xc0);
      iVar3 = iVar4;
    }
    FUN_00407f30(wportal_aut_mutex);
    iVar3 = 0;
    pvVar6 = pvVar1;
    if (param_1 != (code *)0x0) {
      for (; iVar3 < iVar7; iVar3 = iVar3 + 1) {
        (*param_1)(pvVar6,param_2);
        pvVar6 = (void *)((int)pvVar6 + 0xc0);
      }
    }
    FUN_00407df0(pvVar1);
    uVar2 = 0;
  }
  return uVar2;
}

