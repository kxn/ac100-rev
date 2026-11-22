// func uci_read_config_foreach @ 005171cc size=1208

/* WARNING: Type propagation algorithm not settling */

undefined4 uci_read_config_foreach(int param_1,char *param_2,char *param_3,code *param_4)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  void *pvVar5;
  char *pcVar6;
  undefined4 uVar7;
  int *piVar8;
  int *piVar9;
  undefined4 *puVar10;
  void *local_50;
  int local_4c [5];
  int local_38;
  undefined4 *local_34;
  int local_30;
  
  local_4c[0] = 0;
  local_4c[1] = 0;
  local_4c[2] = 0;
  local_4c[3] = 0;
  local_50 = (void *)0x0;
  if ((param_1 == 0) || (param_2 == (char *)0x0)) {
    if (uac_comm_err_switch == 0) {
      return 0xffffffff;
    }
    uVar7 = 0x6f7;
    pcVar6 = "[UAC_COMM_ERR]%s()/line %d : File or type is NULL.\n\n";
  }
  else {
    iVar3 = uci_alloc_context();
    if (iVar3 != 0) {
      local_38 = uci_load(iVar3,param_1,local_4c);
      if (local_38 != 0) {
        if (uac_comm_err_switch != 0) {
          uVar7 = 0x705;
          pcVar6 = "[UAC_COMM_ERR]%s()/line %d : Uci load failed.\n";
LAB_005175cc:
          printf(pcVar6,"uci_read_config_foreach",uVar7);
        }
LAB_00517284:
        if (local_4c[3] != 0) {
          while (iVar4 = uac_list_first(local_4c + 1), iVar4 != 0) {
            uac_list_remove(iVar4);
            uac_mem_free_my(iVar4);
          }
        }
        if (local_38 == 0) {
          uci_free_context();
          return 0;
        }
        uci_get_errorstr(iVar3,&local_50,&DAT_00688af8);
        if (local_50 != (void *)0x0) {
          if (uac_comm_err_switch != 0) {
            printf("[UAC_COMM_ERR]%s()/line %d : Uci with error msg: %s\n","uci_read_config_foreach"
                   ,0x75c);
          }
          free(local_50);
          local_50 = (void *)0x0;
        }
        uci_free_context(iVar3);
        return 0xffffffff;
      }
      piVar1 = local_4c + 1;
      uac_list_init(piVar1);
      piVar9 = *(int **)(local_4c[0] + 0x10);
LAB_00517398:
      do {
        if (piVar9 == (int *)(local_4c[0] + 0x10)) goto LAB_00517284;
        if (((piVar9 != (int *)0x0) && (iVar4 = strcmp(param_2,(char *)piVar9[8]), iVar4 == 0)) &&
           ((param_3 == (char *)0x0 || (iVar4 = strcmp(param_3,(char *)piVar9[3]), iVar4 == 0)))) {
          local_30 = (int)(piVar9 + 4);
          piVar2 = (int *)piVar9[4];
          while (piVar8 = piVar2, piVar8 != (int *)local_30) {
            piVar2 = piRam00000000;
            if (piVar8 != (int *)0x0) {
              if (piVar8[5] == 0) {
                pvVar5 = (void *)uac_mem_malloc_my(400,0x719);
                if (pvVar5 == (void *)0x0) {
                  if (uac_comm_err_switch == 0) goto LAB_00517284;
                  uVar7 = 0x71c;
                  pcVar6 = "[UAC_COMM_ERR]%s()/line %d : Memory is not enough.\n";
                  goto LAB_005175cc;
                }
                memset(pvVar5,0,400);
                *(undefined4 *)((int)pvVar5 + 0xc) = 0;
                strncpy((char *)((int)pvVar5 + 0x10),(char *)piVar8[3],0x7f);
                strncpy((char *)((int)pvVar5 + 0x90),(char *)piVar8[6],0xff);
                uac_list_insert_last(piVar1,pvVar5);
                piVar2 = (int *)*piVar8;
              }
              else if (piVar8[5] == 1) {
                local_34 = piVar8 + 6;
                for (puVar10 = (undefined4 *)piVar8[6]; puVar10 != local_34;
                    puVar10 = (undefined4 *)*puVar10) {
                  pvVar5 = (void *)uac_mem_malloc_my(400,0x72c);
                  if (pvVar5 == (void *)0x0) {
                    if (uac_comm_err_switch == 0) goto LAB_00517284;
                    uVar7 = 0x72f;
                    pcVar6 = "[UAC_COMM_ERR]%s()/line %d : Memory is not enough.\n";
                    goto LAB_005175cc;
                  }
                  memset(pvVar5,0,400);
                  *(undefined4 *)((int)pvVar5 + 0xc) = 1;
                  strncpy((char *)((int)pvVar5 + 0x10),(char *)piVar8[3],0x7f);
                  strncpy((char *)((int)pvVar5 + 0x90),(char *)puVar10[3],0xff);
                  uac_list_insert_last(piVar1,pvVar5);
                }
                piVar2 = (int *)*piVar8;
              }
              else {
                piVar2 = (int *)*piVar8;
              }
            }
          }
          if (local_4c[3] == 0) {
            piVar9 = (int *)*piVar9;
            goto LAB_00517398;
          }
          (*param_4)(piVar1);
          while (iVar4 = uac_list_first(piVar1), iVar4 != 0) {
            uac_list_remove(iVar4);
            uac_mem_free_my(iVar4);
          }
        }
        piVar9 = (int *)*piVar9;
      } while( true );
    }
    if (uac_comm_err_switch == 0) {
      return 0xffffffff;
    }
    uVar7 = 0x6fe;
    pcVar6 = "[UAC_COMM_ERR]%s()/line %d : Alloc uci ctx failed.\n\n";
  }
  printf(pcVar6,"uci_read_config_foreach",uVar7);
  return 0xffffffff;
}

