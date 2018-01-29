cc_library(
  name = "bitree",
  srcs = [
    "bitree.cc",
  ],
)

cc_library(
  name = "bitree_processor",
  srcs = [
    "bitree_processor.cc",
  ],
)

cc_binary(
  name = "main",
  srcs = [
    "main.cc",
  ],
  deps = [
    ":bitree",
    ":bitree_processor",
  ]
)
