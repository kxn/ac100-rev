// func wips_channel_list_to_json @ 004c7e60 size=140

void wips_channel_list_to_json(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  int iVar4;
  undefined4 local_318 [193];
  
  memset(local_318,0,0x300);
  iVar1 = wips_channel_get(param_1,local_318);
  puVar3 = local_318;
  for (iVar4 = 0; iVar4 < iVar1; iVar4 = iVar4 + 1) {
    uVar2 = *puVar3;
    puVar3 = puVar3 + 1;
    uVar2 = json_object_new_int(uVar2);
    json_object_array_add(param_2,uVar2);
  }
  return;
}

