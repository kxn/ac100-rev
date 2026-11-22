// func free_client_hash_node @ 0048bf58 size=76

void free_client_hash_node(int param_1)

{
  if (param_1 == 0) {
    return;
  }
  if (*(int *)(param_1 + 8) != 0) {
    json_object_put();
  }
  FUN_00407df0(param_1);
  return;
}

