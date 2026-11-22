// func mesh_db_ap_entry_add @ 004b6d10 size=1068

undefined4 mesh_db_ap_entry_add(ushort param_1,int param_2,ushort *param_3,int param_4)

{
  ushort uVar1;
  int iVar2;
  uint uVar3;
  void *__s;
  char *pcVar4;
  undefined *puVar5;
  undefined4 uVar6;
  uint uVar7;
  undefined4 uVar8;
  uint uVar9;
  
  uVar9 = (uint)param_1;
  iVar2 = apmngr_db_get_ap_max();
  if (iVar2 <= (int)uVar9) {
    if (mesh_err_switch == '\0') {
      return 0xffffffff;
    }
    printf("[MESH_ERROR]%s()/%d Input error\n","mesh_db_ap_entry_add",0x1de);
    return 0xffffffff;
  }
  FUN_004082d0(DAT_00767eb4,0xffffffff);
  if ((param_4 == 0) && (*(char *)(DAT_00767f6c + uVar9 * 8) != '\0')) {
    uVar8 = 0;
    if (mesh_debug_switch == '\0') goto LAB_004b6dc4;
    pcVar4 = "[MESH_DEBUG]%s()/%d AP id(%d) is used\n";
    uVar6 = 0x1e5;
  }
  else {
    if (param_2 == 0) {
      uVar7 = (uint)param_3[1];
      if (uVar7 == 0xffff) {
        uVar3 = (uint)*param_3;
        if (uVar3 == 0xffff) {
LAB_004b6e94:
          uVar1 = *param_3;
LAB_004b6e98:
          uVar3 = (uint)uVar1;
          if ((uVar3 == 0xffff) || (*(char *)(DAT_00767f6c + uVar3 * 8) != '\0')) {
            pcVar4 = (char *)(DAT_00767f6c + uVar9 * 8);
            if (*pcVar4 == '\0') goto LAB_004b6ee8;
            __s = *(void **)(pcVar4 + 4);
            if ((((__s != (void *)0x0) && (*(int *)((int)__s + 0x10) == 0)) &&
                (*(ushort *)((int)__s + 0x14) != 0xffff)) && (*(ushort *)((int)__s + 0x14) == uVar3)
               ) {
              if (uVar7 != *(ushort *)((int)__s + 0x16)) {
                iVar2 = *(int *)(DAT_00767f6c + uVar7 * 8 + 4);
                if (*(int *)(iVar2 + 0x10) == 0) {
                  if (*(ushort *)(iVar2 + 0x14) != uVar3) {
                    uVar8 = 0xffffffff;
                    if (mesh_err_switch == '\0') goto LAB_004b6dc4;
                    pcVar4 = "[MESH_ERROR]%s()/%d AP id(%d)\'s pap\'s cap id must be same\n";
                    uVar6 = 0x20f;
                    goto LAB_004b6e1c;
                  }
                  uVar1 = *(ushort *)((int)__s + 0xc);
                }
                else {
                  uVar1 = *(ushort *)((int)__s + 0xc);
                }
                if ((uint)uVar1 == (uint)*(ushort *)((int)__s + 0x16)) {
                  uVar7 = (uint)param_3[1];
                }
                else {
                  FUN_00408500(__s);
                  uVar7 = (uint)param_3[1];
                }
                goto LAB_004b6f38;
              }
              goto LAB_004b6f58;
            }
            uVar8 = 0xffffffff;
            if (mesh_err_switch == '\0') goto LAB_004b6dc4;
            pcVar4 = 
            "[MESH_ERROR]%s()/%d AP id(%d)\'s entry is NULL or root changed or cap id changed\n";
            uVar6 = 0x208;
            goto LAB_004b6e1c;
          }
          uVar8 = 0xffffffff;
          if (mesh_err_switch == '\0') goto LAB_004b6dc4;
          pcVar4 = "[MESH_ERROR]%s()/%d AP\'s pap_id(%d) or cap_id(%d) is not used yet\n";
          uVar6 = 0x1fe;
        }
        else {
          uVar8 = 0xffffffff;
          if (mesh_err_switch == '\0') goto LAB_004b6dc4;
          pcVar4 = "[MESH_ERROR]%s()/%d AP\'s pap_id(%d) or cap_id(%d) is illegal\n";
          uVar6 = 499;
          uVar7 = 0xffff;
        }
      }
      else {
        pcVar4 = (char *)(DAT_00767f6c + uVar7 * 8);
        if (*pcVar4 != '\0') {
          iVar2 = *(int *)(pcVar4 + 4);
          if (*(int *)(iVar2 + 0x10) != 0) {
            uVar1 = *param_3;
            goto LAB_004b6e98;
          }
          if (*param_3 == *(ushort *)(iVar2 + 0x14)) goto LAB_004b6e94;
        }
        uVar8 = 0xffffffff;
        if (mesh_err_switch == '\0') goto LAB_004b6dc4;
        uVar3 = (uint)*param_3;
        pcVar4 = "[MESH_ERROR]%s()/%d AP\'s pap_id(%d) or cap_id(%d) is illegal\n";
        uVar6 = 0x1f9;
      }
      uVar8 = 0xffffffff;
      printf(pcVar4,"mesh_db_ap_entry_add",uVar6,uVar7,uVar3);
      goto LAB_004b6dc4;
    }
    if (*(char *)(DAT_00767f6c + uVar9 * 8) == '\0') {
LAB_004b6ee8:
      __s = (void *)FUN_00408450(0x3c,0x21c);
      if (__s == (void *)0x0) {
        uVar8 = 0xffffffff;
        if (mesh_err_switch != '\0') {
          printf("[MESH_ERROR]%s()/%d Malloc failed\n","mesh_db_ap_entry_add",0x21f);
        }
        goto LAB_004b6dc4;
      }
      memset(__s,0,0x3c);
      *(ushort *)((int)__s + 0xc) = param_1;
      *(int *)((int)__s + 0x10) = param_2;
      *(undefined4 *)((int)__s + 0x38) = 0xffffffff;
      FUN_0051ad88((int)__s + 0x20);
      if (param_2 != 0) {
        *(ushort *)((int)__s + 0x16) = param_1;
        *(ushort *)((int)__s + 0x14) = param_1;
        goto LAB_004b6f68;
      }
      uVar7 = (uint)param_3[1];
      if (uVar7 == 0xffff) {
        puVar5 = &DAT_00767f90;
      }
      else {
LAB_004b6f38:
        puVar5 = (undefined *)(*(int *)(DAT_00767f6c + uVar7 * 8 + 4) + 0x20);
      }
      FUN_004086b0(puVar5,__s);
LAB_004b6f58:
      memcpy((void *)((int)__s + 0x14),param_3,0xc);
LAB_004b6f68:
      *(void **)(DAT_00767f6c + uVar9 * 8 + 4) = __s;
      *(undefined1 *)(DAT_00767f6c + uVar9 * 8) = 1;
      FUN_00407f30(DAT_00767eb4);
      return 0;
    }
    uVar8 = 0;
    if (mesh_debug_switch == '\0') goto LAB_004b6dc4;
    pcVar4 = "[MESH_DEBUG]%s()/%d AP id(%d) is used\n";
    uVar6 = 0x1eb;
  }
LAB_004b6e1c:
  printf(pcVar4,"mesh_db_ap_entry_add",uVar6,uVar9);
LAB_004b6dc4:
  FUN_00407f30(DAT_00767eb4);
  return uVar8;
}

