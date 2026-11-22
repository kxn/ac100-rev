// func apmngr_db_entry_cfg_set @ 0053abd0 size=1092

void apmngr_db_entry_cfg_set(uint param_1,int param_2)

{
  uint uVar1;
  int iVar2;
  size_t sVar3;
  size_t sVar4;
  int iVar5;
  undefined1 uVar6;
  uint uVar7;
  uint uVar8;
  char *__s;
  undefined2 *puVar9;
  undefined4 local_30;
  
  param_1 = param_1 & 0xffff;
  if (((apmngr_ap_num_max + apmngr_template_num_max <= (int)param_1) &&
      ((param_1 < 50000 || (apmngr_sensor_num_max + 50000 <= (int)param_1)))) || (param_2 == 0)) {
    if ((apmngr_err_switch != '\0') && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
      printf("[APMNGR_ERROR]%s()/%d Invalid ap id[%d] or cfg_info is NULL.\n",
             "apmngr_db_entry_cfg_set",0x7bf,param_1);
      return;
    }
    return;
  }
  FUN_004082d0(apmngr_db_mutex,0xffffffff);
  iVar2 = g_apmngr_entry_array;
  uVar1 = param_1;
  if (49999 < param_1) {
    uVar1 = (param_1 - 50000) + apmngr_ap_num_max + apmngr_template_num_max;
  }
  if (*(int *)(g_apmngr_entry_array + uVar1 * 0x2d8 + 0x1c) != 1) goto LAB_0053ace4;
  uVar1 = param_1;
  if (49999 < param_1) {
    uVar1 = (param_1 - 50000) + apmngr_ap_num_max + apmngr_template_num_max;
  }
  __s = (char *)(param_2 + 0xe);
  if (*(int *)(g_apmngr_entry_array + uVar1 * 0x2d8 + 0xc) == 2) {
    sVar3 = strlen(__s);
    uVar1 = param_1;
    if (49999 < param_1) {
      uVar1 = (param_1 - 50000) + apmngr_ap_num_max + apmngr_template_num_max;
    }
    sVar4 = strlen((char *)(iVar2 + uVar1 * 0x2d8 + 0x4e));
    if (sVar3 == sVar4 - 3) {
      uVar1 = param_1;
      if (49999 < param_1) {
        uVar1 = (param_1 - 50000) + apmngr_ap_num_max + apmngr_template_num_max;
      }
      iVar5 = strncmp((char *)(iVar2 + uVar1 * 0x2d8 + 0x4e),__s,sVar3);
      if (iVar5 == 0) {
        uVar1 = param_1;
        if (49999 < param_1) {
          uVar1 = (param_1 - 50000) + apmngr_ap_num_max + apmngr_template_num_max;
        }
        memcpy((void *)(param_2 + 0xe),(void *)(iVar2 + uVar1 * 0x2d8 + 0x4e),0x9a);
        goto LAB_0053adac;
      }
    }
    uVar1 = param_1;
    if (49999 < param_1) {
      uVar1 = (param_1 - 50000) + apmngr_ap_num_max + apmngr_template_num_max;
    }
    local_30 = 0;
    uVar8 = (uint)*(ushort *)(iVar2 + uVar1 * 0x2d8 + 0x298);
    uVar1 = uVar8;
    if (49999 < uVar8) {
      uVar1 = (uVar8 - 50000) + apmngr_ap_num_max + apmngr_template_num_max;
    }
    uVar7 = uVar8;
    if (49999 < uVar8) {
      uVar7 = (uVar8 - 50000) + apmngr_ap_num_max + apmngr_template_num_max;
    }
    sVar3 = strlen((char *)(iVar2 + uVar7 * 0x2d8 + 0x4e));
    puVar9 = (undefined2 *)(iVar2 + uVar1 * 0x2d8 + sVar3 + 0x4b);
    local_30 = CONCAT22(*puVar9,CONCAT11(*(undefined1 *)(puVar9 + 1),(undefined1)local_30));
    sVar3 = strlen((char *)&local_30);
    strncat(__s,(char *)&local_30,sVar3);
    if (49999 < uVar8) {
      uVar8 = (uVar8 - 50000) + apmngr_ap_num_max + apmngr_template_num_max;
    }
    strncpy((char *)(iVar2 + uVar8 * 0x2d8 + 0x4e),(char *)(param_2 + 0xe),0x99);
    sVar3 = strlen(__s);
    uVar6 = 0x32;
    iVar5 = param_2 + (sVar3 - 1);
    if (*(char *)(iVar5 + 0xe) != '1') {
      uVar6 = 0x31;
    }
    *(undefined1 *)(iVar5 + 0xe) = uVar6;
  }
LAB_0053adac:
  if (49999 < param_1) {
    param_1 = (param_1 - 50000) + apmngr_ap_num_max + apmngr_template_num_max;
  }
  memcpy((void *)(iVar2 + param_1 * 0x2d8 + 0x4e),(void *)(param_2 + 0xe),0x1ba);
LAB_0053ace4:
  FUN_00407f30(apmngr_db_mutex);
  return;
}

