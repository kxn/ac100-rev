// func cloud_mngt_authentication_type_get @ 0048c614 size=312

void cloud_mngt_authentication_type_get(int param_1,char *param_2,int param_3)

{
  bool bVar1;
  bool bVar2;
  size_t sVar3;
  undefined4 *puVar4;
  uint uVar5;
  undefined4 local_48 [8];
  
  memcpy(local_48,&PTR_DAT_0069b380,0x1c);
  if ((param_1 != 0) && (param_2 != (char *)0x0)) {
    puVar4 = local_48;
    bVar2 = false;
    bVar1 = true;
    uVar5 = 0;
    do {
      if ((*(int *)(param_1 + 0x15c) >> (uVar5 & 0x1f) & 1U) != 0) {
        if (bVar1) {
          bVar1 = false;
          strncpy(param_2,(char *)*puVar4,param_3 - 1);
          bVar2 = true;
          param_2[param_3 + -1] = '\0';
        }
        else {
          sVar3 = strlen(param_2);
          snprintf(param_2 + sVar3,param_3 - sVar3,",%s",*puVar4);
          bVar2 = true;
        }
      }
      uVar5 = uVar5 + 1;
      puVar4 = puVar4 + 1;
    } while (uVar5 != 7);
    if (!bVar2) {
      strncpy(param_2,"none",param_3 - 1);
      param_2[param_3 + -1] = '\0';
    }
  }
  return;
}

