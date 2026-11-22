// func _wportal_free_strategy_del @ 00418960 size=908

undefined4 _wportal_free_strategy_del(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  void *__s;
  int *__s_00;
  int iVar3;
  int iVar4;
  int iVar5;
  char *__src;
  int *piVar6;
  void *pvVar7;
  undefined1 *puVar8;
  undefined4 uVar9;
  char *__dest;
  undefined8 uVar10;
  undefined1 auStack_2b0 [324];
  undefined1 auStack_16c [152];
  int local_d4;
  
  iVar1 = json_object_object_get(param_1,"count");
  if (iVar1 == 0) {
LAB_004189cc:
    if (jcs_err_switch == 0) {
      return 0;
    }
    printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n",
           "_wportal_free_strategy_del",0x1553);
    return 0;
  }
  iVar2 = json_object_get_type(iVar1);
  if (iVar2 == 3) {
    iVar1 = json_object_get_int(iVar1);
  }
  else {
    iVar2 = json_object_get_type();
    if (iVar2 != 2) goto LAB_004189cc;
    uVar10 = json_object_get_double(iVar1);
    iVar1 = __fixdfsi((int)((ulonglong)uVar10 >> 0x20),(int)uVar10);
  }
  if (iVar1 < 1) {
    return 0;
  }
  __s = (void *)FUN_00408450(iVar1 * 0x97,0x1557);
  if (__s == (void *)0x0) {
    return 0xffffffff;
  }
  memset(__s,0,iVar1 * 0x97);
  __s_00 = (int *)FUN_00408450(iVar1 << 2,0x155e);
  if (__s_00 == (int *)0x0) {
    FUN_00407df0(__s);
    return 0xffffffff;
  }
  memset(__s_00,0,iVar1 << 2);
  iVar2 = 0;
  piVar6 = __s_00;
  pvVar7 = __s;
  do {
    iVar2 = iVar2 + 1;
    *piVar6 = (int)pvVar7;
    pvVar7 = (void *)((int)pvVar7 + 0x97);
    piVar6 = piVar6 + 1;
  } while (iVar2 != iVar1);
  iVar2 = json_object_object_get(param_1,"name");
  if (iVar2 == 0) {
LAB_00418b04:
    iVar3 = 0;
    if (jcs_err_switch != 0) {
      printf("[JCS_ERR]%s()/%d Warning: Get stringArray with error obj or value type is unmatch.\n",
             "_wportal_free_strategy_del",0x156c);
      goto LAB_00418b14;
    }
  }
  else {
    iVar3 = json_object_get_type(iVar2);
    if (iVar3 == 5) {
      piVar6 = __s_00;
      for (iVar3 = 0; (iVar4 = json_object_array_length(iVar2), iVar3 < iVar4 && (iVar3 != iVar1));
          iVar3 = iVar3 + 1) {
        iVar4 = json_object_array_get_idx(iVar2,iVar3);
        if ((iVar4 == 0) || (iVar5 = json_object_get_type(iVar4), iVar5 != 6)) {
          if (jcs_err_switch != 0) {
            printf("[JCS_ERR]%s()/%d Warning: Get string with error obj or value type is unmatch.\n"
                   ,"_wportal_free_strategy_del",0x156c);
          }
          __dest = (char *)*piVar6;
          __src = "";
        }
        else {
          __dest = (char *)*piVar6;
          __src = (char *)json_object_get_string(iVar4);
        }
        strncpy(__dest,__src,0x96);
        iVar4 = *piVar6;
        piVar6 = piVar6 + 1;
        *(undefined1 *)(iVar4 + 0x96) = 0;
      }
      goto LAB_00418b14;
    }
    iVar1 = json_object_get_type(iVar2);
    if ((iVar1 != 4) || (iVar1 = json_object_object_length(iVar2), iVar1 != 0)) goto LAB_00418b04;
  }
  iVar3 = 0;
LAB_00418b14:
  iVar1 = 0;
  piVar6 = __s_00;
  do {
    if (iVar3 <= iVar1) {
      FUN_00407df0(__s);
      FUN_00407df0(__s_00);
      return 0;
    }
    memset(auStack_16c,0,0x144);
    iVar4 = wportal_db_ftt_get_by_name(*piVar6,auStack_16c);
    iVar2 = local_d4;
    if (iVar4 != -1) {
      if (local_d4 == 1) {
        puVar8 = auStack_16c;
        uVar9 = 7;
LAB_00418ba4:
        _wportal_update_free_strategy_to_ap(puVar8,uVar9);
      }
      else {
        puVar8 = auStack_16c;
        if (local_d4 == 2) {
LAB_00418ba0:
          uVar9 = 0x12;
          goto LAB_00418ba4;
        }
        if (local_d4 == 3) {
          local_d4 = 1;
          _wportal_update_free_strategy_to_ap(puVar8,7);
          local_d4 = iVar2;
          _wportal_free_strategy_transfer_v4_to_v6(auStack_16c,auStack_2b0);
          puVar8 = auStack_2b0;
          goto LAB_00418ba0;
        }
      }
      wportal_db_ftt_del(*piVar6);
    }
    iVar1 = iVar1 + 1;
    piVar6 = piVar6 + 1;
  } while( true );
}

