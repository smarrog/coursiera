// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: url.proto

#include "url.pb.h"

#include <algorithm>

#include <google/protobuf/stubs/common.h>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/extension_set.h>
#include <google/protobuf/wire_format_lite_inl.h>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/reflection_ops.h>
#include <google/protobuf/wire_format.h>
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>

namespace YellowPages {
class UrlDefaultTypeInternal {
 public:
  ::google::protobuf::internal::ExplicitlyConstructed<Url> _instance;
} _Url_default_instance_;
}  // namespace YellowPages
static void InitDefaultsUrl_url_2eproto() {
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  {
    void* ptr = &::YellowPages::_Url_default_instance_;
    new (ptr) ::YellowPages::Url();
    ::google::protobuf::internal::OnShutdownDestroyMessage(ptr);
  }
  ::YellowPages::Url::InitAsDefaultInstance();
}

::google::protobuf::internal::SCCInfo<0> scc_info_Url_url_2eproto =
    {{ATOMIC_VAR_INIT(::google::protobuf::internal::SCCInfoBase::kUninitialized), 0, InitDefaultsUrl_url_2eproto}, {}};

void InitDefaults_url_2eproto() {
  ::google::protobuf::internal::InitSCC(&scc_info_Url_url_2eproto.base);
}

::google::protobuf::Metadata file_level_metadata_url_2eproto[1];
constexpr ::google::protobuf::EnumDescriptor const** file_level_enum_descriptors_url_2eproto = nullptr;
constexpr ::google::protobuf::ServiceDescriptor const** file_level_service_descriptors_url_2eproto = nullptr;

const ::google::protobuf::uint32 TableStruct_url_2eproto::offsets[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  ~0u,  // no _has_bits_
  PROTOBUF_FIELD_OFFSET(::YellowPages::Url, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  PROTOBUF_FIELD_OFFSET(::YellowPages::Url, value_),
};
static const ::google::protobuf::internal::MigrationSchema schemas[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  { 0, -1, sizeof(::YellowPages::Url)},
};

static ::google::protobuf::Message const * const file_default_instances[] = {
  reinterpret_cast<const ::google::protobuf::Message*>(&::YellowPages::_Url_default_instance_),
};

::google::protobuf::internal::AssignDescriptorsTable assign_descriptors_table_url_2eproto = {
  {}, AddDescriptors_url_2eproto, "url.proto", schemas,
  file_default_instances, TableStruct_url_2eproto::offsets,
  file_level_metadata_url_2eproto, 1, file_level_enum_descriptors_url_2eproto, file_level_service_descriptors_url_2eproto,
};

const char descriptor_table_protodef_url_2eproto[] =
  "\n\turl.proto\022\013YellowPages\"\024\n\003Url\022\r\n\005value"
  "\030\001 \001(\tb\006proto3"
  ;
::google::protobuf::internal::DescriptorTable descriptor_table_url_2eproto = {
  false, InitDefaults_url_2eproto, 
  descriptor_table_protodef_url_2eproto,
  "url.proto", &assign_descriptors_table_url_2eproto, 54,
};

void AddDescriptors_url_2eproto() {
  static constexpr ::google::protobuf::internal::InitFunc deps[1] =
  {
  };
 ::google::protobuf::internal::AddDescriptors(&descriptor_table_url_2eproto, deps, 0);
}

// Force running AddDescriptors() at dynamic initialization time.
static bool dynamic_init_dummy_url_2eproto = []() { AddDescriptors_url_2eproto(); return true; }();
namespace YellowPages {

// ===================================================================

void Url::InitAsDefaultInstance() {
}
class Url::HasBitSetters {
 public:
};

#if !defined(_MSC_VER) || _MSC_VER >= 1900
const int Url::kValueFieldNumber;
#endif  // !defined(_MSC_VER) || _MSC_VER >= 1900

Url::Url()
  : ::google::protobuf::Message(), _internal_metadata_(nullptr) {
  SharedCtor();
  // @@protoc_insertion_point(constructor:YellowPages.Url)
}
Url::Url(const Url& from)
  : ::google::protobuf::Message(),
      _internal_metadata_(nullptr) {
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  value_.UnsafeSetDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  if (from.value().size() > 0) {
    value_.AssignWithDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), from.value_);
  }
  // @@protoc_insertion_point(copy_constructor:YellowPages.Url)
}

void Url::SharedCtor() {
  ::google::protobuf::internal::InitSCC(
      &scc_info_Url_url_2eproto.base);
  value_.UnsafeSetDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}

Url::~Url() {
  // @@protoc_insertion_point(destructor:YellowPages.Url)
  SharedDtor();
}

void Url::SharedDtor() {
  value_.DestroyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}

void Url::SetCachedSize(int size) const {
  _cached_size_.Set(size);
}
const Url& Url::default_instance() {
  ::google::protobuf::internal::InitSCC(&::scc_info_Url_url_2eproto.base);
  return *internal_default_instance();
}


void Url::Clear() {
// @@protoc_insertion_point(message_clear_start:YellowPages.Url)
  ::google::protobuf::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  value_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  _internal_metadata_.Clear();
}

#if GOOGLE_PROTOBUF_ENABLE_EXPERIMENTAL_PARSER
const char* Url::_InternalParse(const char* begin, const char* end, void* object,
                  ::google::protobuf::internal::ParseContext* ctx) {
  auto msg = static_cast<Url*>(object);
  ::google::protobuf::int32 size; (void)size;
  int depth; (void)depth;
  ::google::protobuf::uint32 tag;
  ::google::protobuf::internal::ParseFunc parser_till_end; (void)parser_till_end;
  auto ptr = begin;
  while (ptr < end) {
    ptr = ::google::protobuf::io::Parse32(ptr, &tag);
    GOOGLE_PROTOBUF_PARSER_ASSERT(ptr);
    switch (tag >> 3) {
      // string value = 1;
      case 1: {
        if (static_cast<::google::protobuf::uint8>(tag) != 10) goto handle_unusual;
        ptr = ::google::protobuf::io::ReadSize(ptr, &size);
        GOOGLE_PROTOBUF_PARSER_ASSERT(ptr);
        ctx->extra_parse_data().SetFieldName("YellowPages.Url.value");
        object = msg->mutable_value();
        if (size > end - ptr + ::google::protobuf::internal::ParseContext::kSlopBytes) {
          parser_till_end = ::google::protobuf::internal::GreedyStringParserUTF8;
          goto string_till_end;
        }
        GOOGLE_PROTOBUF_PARSER_ASSERT(::google::protobuf::internal::StringCheckUTF8(ptr, size, ctx));
        ::google::protobuf::internal::InlineGreedyStringParser(object, ptr, size, ctx);
        ptr += size;
        break;
      }
      default: {
      handle_unusual:
        if ((tag & 7) == 4 || tag == 0) {
          ctx->EndGroup(tag);
          return ptr;
        }
        auto res = UnknownFieldParse(tag, {_InternalParse, msg},
          ptr, end, msg->_internal_metadata_.mutable_unknown_fields(), ctx);
        ptr = res.first;
        GOOGLE_PROTOBUF_PARSER_ASSERT(ptr != nullptr);
        if (res.second) return ptr;
      }
    }  // switch
  }  // while
  return ptr;
string_till_end:
  static_cast<::std::string*>(object)->clear();
  static_cast<::std::string*>(object)->reserve(size);
  goto len_delim_till_end;
len_delim_till_end:
  return ctx->StoreAndTailCall(ptr, end, {_InternalParse, msg},
                               {parser_till_end, object}, size);
}
#else  // GOOGLE_PROTOBUF_ENABLE_EXPERIMENTAL_PARSER
bool Url::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!PROTOBUF_PREDICT_TRUE(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:YellowPages.Url)
  for (;;) {
    ::std::pair<::google::protobuf::uint32, bool> p = input->ReadTagWithCutoffNoLastTag(127u);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // string value = 1;
      case 1: {
        if (static_cast< ::google::protobuf::uint8>(tag) == (10 & 0xFF)) {
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_value()));
          DO_(::google::protobuf::internal::WireFormatLite::VerifyUtf8String(
            this->value().data(), static_cast<int>(this->value().length()),
            ::google::protobuf::internal::WireFormatLite::PARSE,
            "YellowPages.Url.value"));
        } else {
          goto handle_unusual;
        }
        break;
      }

      default: {
      handle_unusual:
        if (tag == 0) {
          goto success;
        }
        DO_(::google::protobuf::internal::WireFormat::SkipField(
              input, tag, _internal_metadata_.mutable_unknown_fields()));
        break;
      }
    }
  }
success:
  // @@protoc_insertion_point(parse_success:YellowPages.Url)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:YellowPages.Url)
  return false;
#undef DO_
}
#endif  // GOOGLE_PROTOBUF_ENABLE_EXPERIMENTAL_PARSER

void Url::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:YellowPages.Url)
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  // string value = 1;
  if (this->value().size() > 0) {
    ::google::protobuf::internal::WireFormatLite::VerifyUtf8String(
      this->value().data(), static_cast<int>(this->value().length()),
      ::google::protobuf::internal::WireFormatLite::SERIALIZE,
      "YellowPages.Url.value");
    ::google::protobuf::internal::WireFormatLite::WriteStringMaybeAliased(
      1, this->value(), output);
  }

  if (_internal_metadata_.have_unknown_fields()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        _internal_metadata_.unknown_fields(), output);
  }
  // @@protoc_insertion_point(serialize_end:YellowPages.Url)
}

::google::protobuf::uint8* Url::InternalSerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // @@protoc_insertion_point(serialize_to_array_start:YellowPages.Url)
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  // string value = 1;
  if (this->value().size() > 0) {
    ::google::protobuf::internal::WireFormatLite::VerifyUtf8String(
      this->value().data(), static_cast<int>(this->value().length()),
      ::google::protobuf::internal::WireFormatLite::SERIALIZE,
      "YellowPages.Url.value");
    target =
      ::google::protobuf::internal::WireFormatLite::WriteStringToArray(
        1, this->value(), target);
  }

  if (_internal_metadata_.have_unknown_fields()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields(), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:YellowPages.Url)
  return target;
}

size_t Url::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:YellowPages.Url)
  size_t total_size = 0;

  if (_internal_metadata_.have_unknown_fields()) {
    total_size +=
      ::google::protobuf::internal::WireFormat::ComputeUnknownFieldsSize(
        _internal_metadata_.unknown_fields());
  }
  ::google::protobuf::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  // string value = 1;
  if (this->value().size() > 0) {
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::StringSize(
        this->value());
  }

  int cached_size = ::google::protobuf::internal::ToCachedSize(total_size);
  SetCachedSize(cached_size);
  return total_size;
}

void Url::MergeFrom(const ::google::protobuf::Message& from) {
// @@protoc_insertion_point(generalized_merge_from_start:YellowPages.Url)
  GOOGLE_DCHECK_NE(&from, this);
  const Url* source =
      ::google::protobuf::DynamicCastToGenerated<Url>(
          &from);
  if (source == nullptr) {
  // @@protoc_insertion_point(generalized_merge_from_cast_fail:YellowPages.Url)
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
  // @@protoc_insertion_point(generalized_merge_from_cast_success:YellowPages.Url)
    MergeFrom(*source);
  }
}

void Url::MergeFrom(const Url& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:YellowPages.Url)
  GOOGLE_DCHECK_NE(&from, this);
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  if (from.value().size() > 0) {

    value_.AssignWithDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), from.value_);
  }
}

void Url::CopyFrom(const ::google::protobuf::Message& from) {
// @@protoc_insertion_point(generalized_copy_from_start:YellowPages.Url)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void Url::CopyFrom(const Url& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:YellowPages.Url)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool Url::IsInitialized() const {
  return true;
}

void Url::Swap(Url* other) {
  if (other == this) return;
  InternalSwap(other);
}
void Url::InternalSwap(Url* other) {
  using std::swap;
  _internal_metadata_.Swap(&other->_internal_metadata_);
  value_.Swap(&other->value_, &::google::protobuf::internal::GetEmptyStringAlreadyInited(),
    GetArenaNoVirtual());
}

::google::protobuf::Metadata Url::GetMetadata() const {
  ::google::protobuf::internal::AssignDescriptors(&::assign_descriptors_table_url_2eproto);
  return ::file_level_metadata_url_2eproto[kIndexInFileMessages];
}


// @@protoc_insertion_point(namespace_scope)
}  // namespace YellowPages
namespace google {
namespace protobuf {
template<> PROTOBUF_NOINLINE ::YellowPages::Url* Arena::CreateMaybeMessage< ::YellowPages::Url >(Arena* arena) {
  return Arena::CreateInternal< ::YellowPages::Url >(arena);
}
}  // namespace protobuf
}  // namespace google

// @@protoc_insertion_point(global_scope)
#include <google/protobuf/port_undef.inc>
