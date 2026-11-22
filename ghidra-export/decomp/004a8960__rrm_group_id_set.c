// func _rrm_group_id_set @ 004a8960 size=508

void _rrm_group_id_set(char *param_1)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  int iVar3;
  char *pcVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  undefined4 *puVar8;
  char *local_30 [3];
  
  uVar1 = apmngr_db_get_group_max();
  puVar2 = (undefined4 *)FUN_004082a0(uVar1,4,0x8ca);
  if (puVar2 == (undefined4 *)0x0) {
    if ((rdmngr_err_switch != 0) && (iVar3 = is_target_debug_ap(), iVar3 != 0)) {
      printf("[RDMNGR_ERROR]%s()/%d no memory!\n","_rrm_group_id_set",0x8cd);
    }
  }
  else {
    iVar3 = apmngr_db_get_group_max();
    local_30[0] = (char *)0x0;
    pcVar4 = strtok_r(param_1,",",local_30);
    iVar7 = 0;
    puVar8 = puVar2;
    while (pcVar4 != (char *)0x0) {
      if (iVar3 <= iVar7) goto LAB_004a8a1c;
      *puVar8 = pcVar4;
      iVar7 = iVar7 + 1;
      puVar8 = puVar8 + 1;
      pcVar4 = strtok_r((char *)0x0,",",local_30);
    }
    if (iVar3 > iVar7) {
      puVar2[iVar7] = 0;
    }
LAB_004a8a1c:
    if (iVar7 < 1) {
      if (rrm_err_switch != '\0') {
        printf("[RRM_ERROR]%s()/%d _uac_rrm_util_str_split() fail, str: %s!\n","_rrm_group_id_set",
               0x8d4,param_1);
      }
    }
    else {
      iVar3 = 0;
      memset(&DAT_00731928,0,0x40);
      puVar8 = puVar2;
      do {
        iVar5 = atoi((char *)*puVar8);
        if (iVar5 == -1) {
          memset(&DAT_00731928,0xff,0x40);
          break;
        }
        if ((iVar5 < 0x200) && (-1 < iVar5)) {
          iVar6 = ((int)(iVar5 + 1U) >> 5) + 2;
          (&DAT_00731920)[iVar6] = 1 << (iVar5 + 1U & 0x1f) | (&DAT_00731920)[iVar6];
        }
        iVar3 = iVar3 + 1;
        puVar8 = puVar8 + 1;
      } while (iVar3 != iVar7);
    }
    FUN_00407df0(puVar2);
  }
  return;
}

