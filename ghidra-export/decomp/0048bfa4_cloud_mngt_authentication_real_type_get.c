// func cloud_mngt_authentication_real_type_get @ 0048bfa4 size=188

void cloud_mngt_authentication_real_type_get(uint param_1,char *param_2,int param_3)

{
  int iVar1;
  undefined4 local_30 [8];
  
  memcpy(local_30,&PTR_DAT_0069b380,0x1c);
  if (param_2 == (char *)0x0) {
    return;
  }
  iVar1 = 0;
  if (param_1 != 0) {
    param_1 = param_1 >> 1;
    do {
      if (param_1 == 0) {
        strncpy(param_2,(char *)local_30[iVar1],param_3 - 1);
        param_2[param_3 + -1] = '\0';
        return;
      }
      iVar1 = iVar1 + 1;
      param_1 = param_1 >> 1;
    } while (iVar1 != 7);
  }
  strncpy(param_2,"other",param_3 - 1);
  return;
}

