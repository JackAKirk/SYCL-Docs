// Copyright (c) 2011-2021 The Khronos Group, Inc.
// SPDX-License-Identifier: Apache-2.0

namespace sycl {

template <typename DataT,
          int Dimensions,
          access_mode AccessMode,
          target AccessTarget,
          access::placeholder IsPlaceholder>
class accessor {
 public:
  using value_type =             // const DataT for access_mode::read, DataT otherwise
      __value_type__;
  using reference = value_type &;
  using const_reference = const DataT &;

  /* Available only when: (Dimensions == 0) */
  template <typename AllocatorT>
  accessor(buffer<DataT, 1, AllocatorT> &bufferRef,
           const property_list &propList = {});

  /* Available only when: (Dimensions > 0) */
  template <typename AllocatorT>
  accessor(buffer<DataT, Dimensions, AllocatorT> &bufferRef,
           const property_list &propList = {});

  /* Available only when: (Dimensions > 0) */
  template <typename AllocatorT>
  accessor(buffer<DataT, Dimensions, AllocatorT> &bufferRef,
           range<Dimensions> accessRange, const property_list &propList = {});

  /* Available only when: (Dimensions > 0) */
  template <typename AllocatorT>
  accessor(buffer<DataT, Dimensions, AllocatorT> &bufferRef,
           range<Dimensions> accessRange, id<Dimensions> accessOffset,
           const property_list &propList = {});

  /* -- common interface members -- */

  bool is_placeholder() const;

  size_t get_size() const;

  size_t get_count() const;

  /* Available only when: (Dimensions > 0) */
  range<Dimensions> get_range() const;

  /* Available only when: (Dimensions > 0) */
  id<Dimensions> get_offset() const;

  /* Available only when: (Dimensions == 0) */
  operator reference() const;

  /* Available only when: (Dimensions > 0) */
  reference operator[](id<Dimensions> index) const;

  /* Available only when: (Dimensions > 1) */
  __unspecified__ operator[](size_t index) const;

  /* Available only when: (Dimensions == 1) */
  reference operator[](size_t index) const;

  std::add_pointer_t<value_type> get_pointer() const noexcept;
};

}  // namespace sycl
