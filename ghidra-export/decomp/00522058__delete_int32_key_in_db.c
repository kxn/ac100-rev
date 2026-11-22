// func _delete_int32_key_in_db @ 00522058 size=828

undefined4 _delete_int32_key_in_db(int param_1,int param_2,int param_3,char *param_4,char *param_5)

{
  size_t sVar1;
  size_t sVar2;
  char *pcVar3;
  int iVar4;
  int iVar5;
  undefined4 uVar6;
  int iVar7;
  int iVar8;
  char *pcVar9;
  char *local_840;
  char local_83c [2068];
  
  pcVar3 = local_83c + 0x10;
  local_83c[0] = '\0';
  local_83c[1] = '\0';
  local_83c[2] = '\0';
  local_83c[3] = '\0';
  local_83c[4] = '\0';
  local_83c[5] = '\0';
  local_83c[6] = '\0';
  local_83c[7] = '\0';
  local_83c[8] = '\0';
  local_83c[9] = '\0';
  local_83c[10] = '\0';
  local_83c[0xb] = '\0';
  local_83c[0xc] = '\0';
  local_83c[0xd] = '\0';
  local_83c[0xe] = '\0';
  local_83c[0xf] = '\0';
  local_840 = (char *)0x0;
  memset(pcVar3,0,0x800);
  if ((((param_1 == 0) || (param_3 == 0)) || (param_4 == (char *)0x0)) || (param_5 == (char *)0x0))
  {
    uVar6 = 1;
    iVar7 = uac_sqlite_err_switch_get();
    if (iVar7 != 0) {
      printf("[UAC_QLITE_ERROR]%s()/line %d : Invalid paramas %d %d %d %d.\n",
             "_delete_int32_key_in_db",0x131,(uint)(param_3 == 0),(uint)(param_1 == 0),
             (uint)(param_4 == (char *)0x0),(uint)(param_5 == (char *)0x0));
    }
  }
  else {
    sVar1 = strlen(param_4);
    sVar2 = strlen(param_5);
    if (sVar2 + sVar1 < 0x15c) {
      iVar7 = 0;
      if (0 < param_2) {
        do {
          memset(pcVar3,0,0x800);
          iVar8 = iVar7 * 4;
          iVar5 = 0;
          pcVar9 = param_5;
          snprintf(pcVar3,0x800,"delete from %s where %s in ( ",param_4,param_5);
          while (iVar4 = *(int *)(param_1 + iVar8 + iVar5 * 4), iVar4 != -1) {
            local_83c[0] = '\0';
            local_83c[1] = '\0';
            local_83c[2] = '\0';
            local_83c[3] = '\0';
            local_83c[4] = '\0';
            local_83c[5] = '\0';
            local_83c[6] = '\0';
            local_83c[7] = '\0';
            local_83c[8] = '\0';
            local_83c[9] = '\0';
            local_83c[10] = '\0';
            local_83c[0xb] = '\0';
            local_83c[0xc] = '\0';
            local_83c[0xd] = '\0';
            local_83c[0xe] = '\0';
            local_83c[0xf] = '\0';
            snprintf(local_83c,0x10,"%d",iVar4,pcVar9);
            if (iVar5 != 0) {
              strcat(pcVar3,", ");
            }
            iVar5 = iVar5 + 1;
            strcat(pcVar3,local_83c);
            iVar7 = iVar7 + 1;
            if ((iVar5 == 0x96) || (param_2 <= iVar7)) goto LAB_00522218;
          }
          if (iVar5 == 0) goto LAB_00522258;
LAB_00522218:
          strcat(pcVar3,")");
          iVar5 = sqlite3_exec(param_3,pcVar3,0,0,&local_840);
          if (iVar5 != 0) {
            iVar7 = uac_sqlite_err_switch_get();
            if (iVar7 != 0) {
              pcVar3 = local_840;
              if (local_840 == (char *)0x0) {
                pcVar3 = "null";
              }
              printf("[UAC_QLITE_ERROR]%s()/line %d : delete %s fail, err_msg=%s\n",
                     "_delete_int32_key_in_db",0x151,param_4,pcVar3);
            }
            if (local_840 == (char *)0x0) {
              return 1;
            }
            uac_sqlite_free();
            return 1;
          }
LAB_00522258:
        } while (iVar7 < param_2);
      }
      uVar6 = 0;
    }
    else {
      uVar6 = 1;
      iVar7 = uac_sqlite_err_switch_get();
      if (iVar7 != 0) {
        printf("[UAC_QLITE_ERROR]%s()/line %d : tablename or key name too long\n",
               "_delete_int32_key_in_db",0x137);
      }
    }
  }
  return uVar6;
}

