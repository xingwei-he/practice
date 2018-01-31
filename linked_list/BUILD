cc_library (
  name = "linked_list_processor",
  srcs = [
    "linked_list_processor.cc",
  ],
)

cc_library (
  name = "linked_list",
  srcs = [
    "linked_list.cc",
  ],
)

cc_binary (
  name = "main",
  srcs = [
    "main.cc",
  ],
  deps = [
    ":linked_list",
    ":linked_list_processor",
  ],
)
