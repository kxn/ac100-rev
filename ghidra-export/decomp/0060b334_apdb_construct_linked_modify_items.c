// func apdb_construct_linked_modify_items @ 0060b334 size=8

undefined4 apdb_construct_linked_modify_items(int *param_1,char *param_2,size_t param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  if (param_2 == (char *)0x0) {
    uVar2 = 0xffffffff;
    if (apdb_err_switch != 0) {
      printf("[APDB_ERROR]%s()/line %d : input string data null.\n",
             "_apdb_construct_linked_modify_items",0x665);
    }
  }
  else {
    iVar1 = 0;
    memset(param_2,0,param_3);
    if (*param_1 == 1) {
      if (param_3 < 7) {
        return 0xffffffff;
      }
      param_3 = param_3 - 5;
      strcat(param_2,"chnl,");
      iVar1 = 5;
    }
    if (param_1[1] == 1) {
      if (param_3 < 7) {
        return 0xffffffff;
      }
      param_3 = param_3 - 5;
      strcat(param_2,"rdMd,");
      iVar1 = iVar1 + 5;
    }
    if (param_1[2] == 1) {
      if (param_3 < 7) {
        return 0xffffffff;
      }
      param_3 = param_3 - 5;
      strcat(param_2,"bwMd,");
      iVar1 = iVar1 + 5;
    }
    if (param_1[3] == 1) {
      if (param_3 < 6) {
        return 0xffffffff;
      }
      param_3 = param_3 - 4;
      strcat(param_2,"wmm,");
      iVar1 = iVar1 + 4;
    }
    if (param_1[4] == 1) {
      if (param_3 < 6) {
        return 0xffffffff;
      }
      param_3 = param_3 - 4;
      strcat(param_2,"brd,");
      iVar1 = iVar1 + 4;
    }
    if (param_1[5] == 1) {
      if (param_3 < 9) {
        return 0xffffffff;
      }
      param_3 = param_3 - 7;
      strcat(param_2,"maxUsr,");
      iVar1 = iVar1 + 7;
    }
    if (param_1[6] == 1) {
      if (param_3 < 7) {
        return 0xffffffff;
      }
      param_3 = param_3 - 5;
      strcat(param_2,"rssi,");
      iVar1 = iVar1 + 5;
    }
    if (param_1[7] == 1) {
      if (param_3 < 6) {
        return 0xffffffff;
      }
      param_3 = param_3 - 4;
      strcat(param_2,"dcs,");
      iVar1 = iVar1 + 4;
    }
    if (param_1[8] == 1) {
      if (param_3 < 9) {
        return 0xffffffff;
      }
      param_3 = param_3 - 7;
      strcat(param_2,"beacon,");
      iVar1 = iVar1 + 7;
    }
    if (param_1[9] == 1) {
      if (param_3 < 7) {
        return 0xffffffff;
      }
      iVar1 = iVar1 + 5;
      strcat(param_2,"wlan,");
    }
    uVar2 = 0;
    param_2[iVar1 + -1] = '\0';
  }
  return uVar2;
}

