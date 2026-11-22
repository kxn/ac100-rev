// func apmngr_db_role_bitmap_get @ 00534228 size=664

uint apmngr_db_role_bitmap_get(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  char *__s2;
  char *pcVar6;
  uint *puVar7;
  int iVar8;
  uint *puVar9;
  uint local_58 [10];
  int local_30;
  
  memset(local_58,0,0x24);
  if (param_1 == 0) {
    return 0xf0000;
  }
  iVar1 = json_object_object_get(param_1,"ap_role");
  if (iVar1 == 0) {
    return 0xf0000;
  }
  iVar2 = json_object_get_type(iVar1);
  if (iVar2 != 5) {
    return 0xf0000;
  }
  iVar2 = json_object_array_length(iVar1);
  if (iVar2 < 1) {
    return 0xf0000;
  }
  iVar2 = json_object_get_type(iVar1);
  puVar7 = local_58;
  if (iVar2 == 5) {
    puVar9 = puVar7;
    for (iVar2 = 0; iVar3 = json_object_array_length(iVar1), iVar2 < iVar3; iVar2 = iVar2 + 1) {
      if (iVar2 == 9) goto LAB_005343e4;
      iVar3 = json_object_array_get_idx(iVar1,iVar2);
      if (iVar3 == 0) {
LAB_005343a4:
        if (jcs_err_switch == 0) {
          uVar5 = 0xffffffff;
        }
        else {
          printf("[JCS_ERR]%s()/%d Warning: transfer string to int failed.\n",
                 "apmngr_db_role_bitmap_get",0x12e);
          uVar5 = 0xffffffff;
        }
      }
      else {
        iVar4 = json_object_get_type(iVar3);
        iVar8 = 0;
        if (iVar4 != 6) {
          if (jcs_err_switch != 0) {
            pcVar6 = "[JCS_ERR]%s()/%d Warning: obj type not string, parse failed.\n";
LAB_00534410:
            printf(pcVar6,"apmngr_db_role_bitmap_get",0x12e);
          }
          goto LAB_005343a4;
        }
        do {
          while( true ) {
            if (ap_role_map_bitmap <= iVar8) {
              if (jcs_err_switch == 0) goto LAB_005343a4;
              pcVar6 = "[JCS_ERR]%s()/%d Warning: map string to int failed.\n";
              goto LAB_00534410;
            }
            local_30 = iVar8 * 0x10;
            pcVar6 = *(char **)(PTR__mt_ap_role_bitmap_0074bf14 + local_30);
            if (pcVar6 != (char *)0x0) break;
            iVar8 = iVar8 + 1;
          }
          __s2 = (char *)json_object_get_string(iVar3);
          iVar4 = strcmp(pcVar6,__s2);
          iVar8 = iVar8 + 1;
        } while (iVar4 != 0);
        uVar5 = *(uint *)(PTR__mt_ap_role_bitmap_0074bf14 + local_30 + 0xc);
      }
      *puVar9 = uVar5;
      puVar9 = puVar9 + 1;
    }
    if (0 < iVar2) {
LAB_005343e4:
      uVar5 = 0;
      iVar1 = 0;
      do {
        iVar1 = iVar1 + 1;
        uVar5 = uVar5 | *puVar7;
        puVar7 = puVar7 + 1;
      } while (iVar1 < iVar2);
      return uVar5;
    }
  }
  else {
    iVar2 = json_object_get_type(iVar1);
    if ((iVar2 == 4) && (iVar1 = json_object_object_length(iVar1), iVar1 == 0)) {
      return 0xf0000;
    }
    if (jcs_err_switch != 0) {
      printf("[JCS_ERR]%s()/%d Warning: Trans intArray with error obj or value type is unmatch.\n",
             "apmngr_db_role_bitmap_get",0x12e);
      return 0xf0000;
    }
  }
  return 0xf0000;
}

