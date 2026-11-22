// func add_client_hash_node @ 00491cc4 size=48

void add_client_hash_node(int param_1,int param_2)

{
  if (((param_1 != 0) && (param_2 != 0)) && (*(int *)(param_1 + 8) != 0)) {
    json_object_array_add(param_2,*(int *)(param_1 + 8));
    return;
  }
  return;
}

