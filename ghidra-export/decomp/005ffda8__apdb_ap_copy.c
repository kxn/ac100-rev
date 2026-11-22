// func _apdb_ap_copy @ 005ffda8 size=796

void _apdb_ap_copy(void *param_1,void *param_2,int param_3)

{
  void *pvVar1;
  int iVar2;
  void *pvVar3;
  int iVar4;
  void *__src;
  int iVar5;
  int iVar6;
  
  if (((param_1 != (void *)0x0) && (param_2 != (void *)0x0)) && (0 < param_3)) {
    _apdb_ap_model_free(param_1,param_3);
    iVar6 = 0;
    memcpy(param_1,param_2,param_3 * 0x168);
    do {
      *(undefined4 *)((int)param_1 + 0x164) = 0;
      if (0 < *(int *)((int)param_1 + 0x160)) {
        pvVar1 = (void *)FUN_00408450(*(int *)((int)param_1 + 0x160) * 0x38,0x32e);
        *(void **)((int)param_1 + 0x164) = pvVar1;
        if (pvVar1 == (void *)0x0) {
          *(undefined4 *)((int)param_1 + 0x160) = 0;
        }
        else {
          memset(pvVar1,0,*(int *)((int)param_1 + 0x160) * 0x38);
          iVar2 = *(int *)((int)param_2 + 0x160);
          pvVar1 = *(void **)((int)param_1 + 0x164);
          __src = *(void **)((int)param_2 + 0x164);
          if ((pvVar1 != (void *)0x0) && (iVar5 = 0, __src != (void *)0x0)) {
            for (; iVar5 < iVar2; iVar5 = iVar5 + 1) {
              _apdb_ap_model_radios_free(pvVar1,1);
              _apdb_ap_model_phy_info_free(pvVar1,1);
              _apdb_ap_model_rrst_free(pvVar1,1);
              _apdb_ap_model_region_list_free(pvVar1,1);
              memcpy(pvVar1,__src,0x38);
              *(undefined4 *)((int)pvVar1 + 0x28) = 0;
              if (0 < *(int *)((int)pvVar1 + 0x10)) {
                pvVar3 = (void *)FUN_00408450(*(int *)((int)pvVar1 + 0x10) * 0x114,0x2e1);
                *(void **)((int)pvVar1 + 0x28) = pvVar3;
                if (pvVar3 != (void *)0x0) {
                  memset(pvVar3,0,*(int *)((int)pvVar1 + 0x10) * 0x114);
                  _apdb_radio_copy(*(undefined4 *)((int)pvVar1 + 0x28),
                                   *(undefined4 *)((int)__src + 0x28),
                                   *(undefined4 *)((int)pvVar1 + 0x10));
                  goto LAB_005fff70;
                }
                *(undefined4 *)((int)pvVar1 + 0x10) = 0;
LAB_0060000c:
                _apdb_ap_model_radios_free(pvVar1,1);
                _apdb_ap_model_phy_info_free(pvVar1,1);
                _apdb_ap_model_rrst_free(pvVar1,1);
                _apdb_ap_model_region_list_free(pvVar1,1);
                break;
              }
LAB_005fff70:
              if (*(byte *)((int)pvVar1 + 0x14) == 0) {
                iVar4 = *(int *)((int)pvVar1 + 4);
              }
              else {
                pvVar3 = (void *)FUN_00408450((uint)*(byte *)((int)pvVar1 + 0x14) << 3,0x2ee);
                *(void **)((int)pvVar1 + 0x2c) = pvVar3;
                if (pvVar3 == (void *)0x0) {
                  *(undefined1 *)((int)pvVar1 + 0x14) = 0;
                  goto LAB_0060000c;
                }
                memset(pvVar3,0,(uint)*(byte *)((int)pvVar1 + 0x14) << 3);
                memcpy(*(void **)((int)pvVar1 + 0x2c),*(void **)((int)__src + 0x2c),
                       (uint)*(byte *)((int)pvVar1 + 0x14) << 3);
                iVar4 = *(int *)((int)pvVar1 + 4);
              }
              *(undefined4 *)((int)pvVar1 + 0x34) = 0;
              if (0 < iVar4) {
                pvVar3 = (void *)FUN_00408450(iVar4 * 0x1fc,0x2fc);
                *(void **)((int)pvVar1 + 0x34) = pvVar3;
                if (pvVar3 == (void *)0x0) {
                  *(undefined4 *)((int)pvVar1 + 4) = 0;
                  goto LAB_0060000c;
                }
                memset(pvVar3,0,*(int *)((int)pvVar1 + 4) * 0x1fc);
                memcpy(*(void **)((int)pvVar1 + 0x34),*(void **)((int)__src + 0x34),
                       *(int *)((int)pvVar1 + 4) * 0x1fc);
              }
              *(undefined4 *)((int)pvVar1 + 0x30) = 0;
              if (*(byte *)((int)pvVar1 + 0x15) != 0) {
                pvVar3 = (void *)FUN_00408450((uint)*(byte *)((int)pvVar1 + 0x15) * 0xc3,0x30b);
                *(void **)((int)pvVar1 + 0x30) = pvVar3;
                if (pvVar3 == (void *)0x0) {
                  *(undefined1 *)((int)pvVar1 + 0x15) = 0;
                  if (apdb_err_switch != 0) {
                    printf("[APDB_ERROR]%s()/line %d : malloc error\n","_apdb_model_copy",0x30f);
                  }
                  goto LAB_0060000c;
                }
                memset(pvVar3,0,(uint)*(byte *)((int)pvVar1 + 0x15) * 0xc3);
                memcpy(*(void **)((int)pvVar1 + 0x30),*(void **)((int)__src + 0x30),
                       (uint)*(byte *)((int)pvVar1 + 0x15) * 0xc3);
              }
              pvVar1 = (void *)((int)pvVar1 + 0x38);
              __src = (void *)((int)__src + 0x38);
            }
          }
        }
      }
      iVar6 = iVar6 + 1;
      param_1 = (void *)((int)param_1 + 0x168);
      param_2 = (void *)((int)param_2 + 0x168);
    } while (iVar6 != param_3);
  }
  return;
}

