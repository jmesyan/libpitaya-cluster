// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: session.proto

#ifndef PROTOBUF_INCLUDED_session_2eproto
#define PROTOBUF_INCLUDED_session_2eproto

#include <string>

#include <google/protobuf/stubs/common.h>

#if GOOGLE_PROTOBUF_VERSION < 3006001
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please update
#error your headers.
#endif
#if 3006001 < GOOGLE_PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/arena.h>
#include <google/protobuf/arenastring.h>
#include <google/protobuf/generated_message_table_driven.h>
#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/inlined_string_field.h>
#include <google/protobuf/metadata.h>
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>  // IWYU pragma: export
#include <google/protobuf/extension_set.h>  // IWYU pragma: export
#include <google/protobuf/unknown_field_set.h>
// @@protoc_insertion_point(includes)
#define PROTOBUF_INTERNAL_EXPORT_protobuf_session_2eproto 

namespace protobuf_session_2eproto {
// Internal implementation detail -- do not use these members.
struct TableStruct {
  static const ::google::protobuf::internal::ParseTableField entries[];
  static const ::google::protobuf::internal::AuxillaryParseTableField aux[];
  static const ::google::protobuf::internal::ParseTable schema[1];
  static const ::google::protobuf::internal::FieldMetadata field_metadata[];
  static const ::google::protobuf::internal::SerializationTable serialization_table[];
  static const ::google::protobuf::uint32 offsets[];
};
void AddDescriptors();
}  // namespace protobuf_session_2eproto
namespace protos {
class Session;
class SessionDefaultTypeInternal;
extern SessionDefaultTypeInternal _Session_default_instance_;
}  // namespace protos
namespace google {
namespace protobuf {
template<> ::protos::Session* Arena::CreateMaybeMessage<::protos::Session>(Arena*);
}  // namespace protobuf
}  // namespace google
namespace protos {

// ===================================================================

class Session : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:protos.Session) */ {
 public:
  Session();
  virtual ~Session();

  Session(const Session& from);

  inline Session& operator=(const Session& from) {
    CopyFrom(from);
    return *this;
  }
  #if LANG_CXX11
  Session(Session&& from) noexcept
    : Session() {
    *this = ::std::move(from);
  }

  inline Session& operator=(Session&& from) noexcept {
    if (GetArenaNoVirtual() == from.GetArenaNoVirtual()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }
  #endif
  static const ::google::protobuf::Descriptor* descriptor();
  static const Session& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const Session* internal_default_instance() {
    return reinterpret_cast<const Session*>(
               &_Session_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    0;

  void Swap(Session* other);
  friend void swap(Session& a, Session& b) {
    a.Swap(&b);
  }

  // implements Message ----------------------------------------------

  inline Session* New() const final {
    return CreateMaybeMessage<Session>(NULL);
  }

  Session* New(::google::protobuf::Arena* arena) const final {
    return CreateMaybeMessage<Session>(arena);
  }
  void CopyFrom(const ::google::protobuf::Message& from) final;
  void MergeFrom(const ::google::protobuf::Message& from) final;
  void CopyFrom(const Session& from);
  void MergeFrom(const Session& from);
  void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input) final;
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const final;
  ::google::protobuf::uint8* InternalSerializeWithCachedSizesToArray(
      bool deterministic, ::google::protobuf::uint8* target) const final;
  int GetCachedSize() const final { return _cached_size_.Get(); }

  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(Session* other);
  private:
  inline ::google::protobuf::Arena* GetArenaNoVirtual() const {
    return NULL;
  }
  inline void* MaybeArenaPtr() const {
    return NULL;
  }
  public:

  ::google::protobuf::Metadata GetMetadata() const final;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // string uid = 2;
  void clear_uid();
  static const int kUidFieldNumber = 2;
  const ::std::string& uid() const;
  void set_uid(const ::std::string& value);
  #if LANG_CXX11
  void set_uid(::std::string&& value);
  #endif
  void set_uid(const char* value);
  void set_uid(const char* value, size_t size);
  ::std::string* mutable_uid();
  ::std::string* release_uid();
  void set_allocated_uid(::std::string* uid);

  // bytes data = 3;
  void clear_data();
  static const int kDataFieldNumber = 3;
  const ::std::string& data() const;
  void set_data(const ::std::string& value);
  #if LANG_CXX11
  void set_data(::std::string&& value);
  #endif
  void set_data(const char* value);
  void set_data(const void* value, size_t size);
  ::std::string* mutable_data();
  ::std::string* release_data();
  void set_allocated_data(::std::string* data);

  // int64 id = 1;
  void clear_id();
  static const int kIdFieldNumber = 1;
  ::google::protobuf::int64 id() const;
  void set_id(::google::protobuf::int64 value);

  // @@protoc_insertion_point(class_scope:protos.Session)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  ::google::protobuf::internal::ArenaStringPtr uid_;
  ::google::protobuf::internal::ArenaStringPtr data_;
  ::google::protobuf::int64 id_;
  mutable ::google::protobuf::internal::CachedSize _cached_size_;
  friend struct ::protobuf_session_2eproto::TableStruct;
};
// ===================================================================


// ===================================================================

#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// Session

// int64 id = 1;
inline void Session::clear_id() {
  id_ = GOOGLE_LONGLONG(0);
}
inline ::google::protobuf::int64 Session::id() const {
  // @@protoc_insertion_point(field_get:protos.Session.id)
  return id_;
}
inline void Session::set_id(::google::protobuf::int64 value) {
  
  id_ = value;
  // @@protoc_insertion_point(field_set:protos.Session.id)
}

// string uid = 2;
inline void Session::clear_uid() {
  uid_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline const ::std::string& Session::uid() const {
  // @@protoc_insertion_point(field_get:protos.Session.uid)
  return uid_.GetNoArena();
}
inline void Session::set_uid(const ::std::string& value) {
  
  uid_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:protos.Session.uid)
}
#if LANG_CXX11
inline void Session::set_uid(::std::string&& value) {
  
  uid_.SetNoArena(
    &::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::move(value));
  // @@protoc_insertion_point(field_set_rvalue:protos.Session.uid)
}
#endif
inline void Session::set_uid(const char* value) {
  GOOGLE_DCHECK(value != NULL);
  
  uid_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:protos.Session.uid)
}
inline void Session::set_uid(const char* value, size_t size) {
  
  uid_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:protos.Session.uid)
}
inline ::std::string* Session::mutable_uid() {
  
  // @@protoc_insertion_point(field_mutable:protos.Session.uid)
  return uid_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* Session::release_uid() {
  // @@protoc_insertion_point(field_release:protos.Session.uid)
  
  return uid_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void Session::set_allocated_uid(::std::string* uid) {
  if (uid != NULL) {
    
  } else {
    
  }
  uid_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), uid);
  // @@protoc_insertion_point(field_set_allocated:protos.Session.uid)
}

// bytes data = 3;
inline void Session::clear_data() {
  data_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline const ::std::string& Session::data() const {
  // @@protoc_insertion_point(field_get:protos.Session.data)
  return data_.GetNoArena();
}
inline void Session::set_data(const ::std::string& value) {
  
  data_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:protos.Session.data)
}
#if LANG_CXX11
inline void Session::set_data(::std::string&& value) {
  
  data_.SetNoArena(
    &::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::move(value));
  // @@protoc_insertion_point(field_set_rvalue:protos.Session.data)
}
#endif
inline void Session::set_data(const char* value) {
  GOOGLE_DCHECK(value != NULL);
  
  data_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:protos.Session.data)
}
inline void Session::set_data(const void* value, size_t size) {
  
  data_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:protos.Session.data)
}
inline ::std::string* Session::mutable_data() {
  
  // @@protoc_insertion_point(field_mutable:protos.Session.data)
  return data_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* Session::release_data() {
  // @@protoc_insertion_point(field_release:protos.Session.data)
  
  return data_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void Session::set_allocated_data(::std::string* data) {
  if (data != NULL) {
    
  } else {
    
  }
  data_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), data);
  // @@protoc_insertion_point(field_set_allocated:protos.Session.data)
}

#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__

// @@protoc_insertion_point(namespace_scope)

}  // namespace protos

// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_INCLUDED_session_2eproto
