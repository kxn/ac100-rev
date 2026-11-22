// func uac_schedule_container_hash_dump @ 00521b14 size=120

void uac_schedule_container_hash_dump(int param_1)

{
  undefined4 uVar1;
  
  puts("*************************container dump**************************");
  uVar1 = uac_list_size(param_1 + 0x34);
  printf("data num:%d\n",uVar1);
  puts("*****************************************************************");
  return;
}

