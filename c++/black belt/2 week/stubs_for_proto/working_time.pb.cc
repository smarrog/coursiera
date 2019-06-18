// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: working_time.proto

#include "working_time.pb.h"

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

extern PROTOBUF_INTERNAL_EXPORT_working_5ftime_2eproto ::google::protobuf::internal::SCCInfo<0> scc_info_WorkingTimeInterval_working_5ftime_2eproto;
namespace YellowPages {
class WorkingTimeIntervalDefaultTypeInternal {
 public:
  ::google::protobuf::internal::ExplicitlyConstructed<WorkingTimeInterval> _instance;
} _WorkingTimeInterval_default_instance_;
class WorkingTimeDefaultTypeInternal {
 public:
  ::google::protobuf::internal::ExplicitlyConstructed<WorkingTime> _instance;
} _WorkingTime_default_instance_;
}  // namespace YellowPages
static void InitDefaultsWorkingTimeInterval_working_5ftime_2eproto() {
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  {
    void* ptr = &::YellowPages::_WorkingTimeInterval_default_instance_;
    new (ptr) ::YellowPages::WorkingTimeInterval();
    ::google::protobuf::internal::OnShutdownDestroyMessage(ptr);
  }
  ::YellowPages::WorkingTimeInterval::InitAsDefaultInstance();
}

::google::protobuf::internal::SCCInfo<0> scc_info_WorkingTimeInterval_working_5ftime_2eproto =
    {{ATOMIC_VAR_INIT(::google::protobuf::internal::SCCInfoBase::kUninitialized), 0, InitDefaultsWorkingTimeInterval_working_5ftime_2eproto}, {}};

static void InitDefaultsWorkingTime_working_5ftime_2eproto() {
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  {
    void* ptr = &::YellowPages::_WorkingTime_default_instance_;
    new (ptr) ::YellowPages::WorkingTime();
    ::google::protobuf::internal::OnShutdownDestroyMessage(ptr);
  }
  ::YellowPages::WorkingTime::InitAsDefaultInstance();
}

::google::protobuf::internal::SCCInfo<1> scc_info_WorkingTime_working_5ftime_2eproto =
    {{ATOMIC_VAR_INIT(::google::protobuf::internal::SCCInfoBase::kUninitialized), 1, InitDefaultsWorkingTime_working_5ftime_2eproto}, {
      &scc_info_WorkingTimeInterval_working_5ftime_2eproto.base,}};

void InitDefaults_working_5ftime_2eproto() {
  ::google::protobuf::internal::InitSCC(&scc_info_WorkingTimeInterval_working_5ftime_2eproto.base);
  ::google::protobuf::internal::InitSCC(&scc_info_WorkingTime_working_5ftime_2eproto.base);
}

::google::protobuf::Metadata file_level_metadata_working_5ftime_2eproto[2];
const ::google::protobuf::EnumDescriptor* file_level_enum_descriptors_working_5ftime_2eproto[1];
constexpr ::google::protobuf::ServiceDescriptor const** file_level_service_descriptors_working_5ftime_2eproto = nullptr;

const ::google::protobuf::uint32 TableStruct_working_5ftime_2eproto::offsets[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  ~0u,  // no _has_bits_
  PROTOBUF_FIELD_OFFSET(::YellowPages::WorkingTimeInterval, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  PROTOBUF_FIELD_OFFSET(::YellowPages::WorkingTimeInterval, day_),
  PROTOBUF_FIELD_OFFSET(::YellowPages::WorkingTimeInterval, minutes_from_),
  PROTOBUF_FIELD_OFFSET(::YellowPages::WorkingTimeInterval, minutes_to_),
  ~0u,  // no _has_bits_
  PROTOBUF_FIELD_OFFSET(::YellowPages::WorkingTime, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  PROTOBUF_FIELD_OFFSET(::YellowPages::WorkingTime, formatted_),
  PROTOBUF_FIELD_OFFSET(::YellowPages::WorkingTime, intervals_),
};
static const ::google::protobuf::internal::MigrationSchema schemas[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  { 0, -1, sizeof(::YellowPages::WorkingTimeInterval)},
  { 8, -1, sizeof(::YellowPages::WorkingTime)},
};

static ::google::protobuf::Message const * const file_default_instances[] = {
  reinterpret_cast<const ::google::protobuf::Message*>(&::YellowPages::_WorkingTimeInterval_default_instance_),
  reinterpret_cast<const ::google::protobuf::Message*>(&::YellowPages::_WorkingTime_default_instance_),
};

::google::protobuf::internal::AssignDescriptorsTable assign_descriptors_table_working_5ftime_2eproto = {
  {}, AddDescriptors_working_5ftime_2eproto, "working_time.proto", schemas,
  file_default_instances, TableStruct_working_5ftime_2eproto::offsets,
  file_level_metadata_working_5ftime_2eproto, 2, file_level_enum_descriptors_working_5ftime_2eproto, file_level_service_descriptors_working_5ftime_2eproto,
};

const char descriptor_table_protodef_working_5ftime_2eproto[] =
  "\n\022working_time.proto\022\013YellowPages\"\343\001\n\023Wo"
  "rkingTimeInterval\0221\n\003day\030\001 \001(\0162$.YellowP"
  "ages.WorkingTimeInterval.Day\022\024\n\014minutes_"
  "from\030\002 \001(\005\022\022\n\nminutes_to\030\003 \001(\005\"o\n\003Day\022\014\n"
  "\010EVERYDAY\020\000\022\n\n\006MONDAY\020\001\022\013\n\007TUESDAY\020\002\022\r\n\t"
  "WEDNESDAY\020\003\022\014\n\010THURSDAY\020\004\022\n\n\006FRIDAY\020\005\022\014\n"
  "\010SATURDAY\020\006\022\n\n\006SUNDAY\020\007\"U\n\013WorkingTime\022\021"
  "\n\tformatted\030\001 \001(\t\0223\n\tintervals\030\002 \003(\0132 .Y"
  "ellowPages.WorkingTimeIntervalb\006proto3"
  ;
::google::protobuf::internal::DescriptorTable descriptor_table_working_5ftime_2eproto = {
  false, InitDefaults_working_5ftime_2eproto, 
  descriptor_table_protodef_working_5ftime_2eproto,
  "working_time.proto", &assign_descriptors_table_working_5ftime_2eproto, 358,
};

void AddDescriptors_working_5ftime_2eproto() {
  static constexpr ::google::protobuf::internal::InitFunc deps[1] =
  {
  };
 ::google::protobuf::internal::AddDescriptors(&descriptor_table_working_5ftime_2eproto, deps, 0);
}

// Force running AddDescriptors() at dynamic initialization time.
static bool dynamic_init_dummy_working_5ftime_2eproto = []() { AddDescriptors_working_5ftime_2eproto(); return true; }();
namespace YellowPages {
const ::google::protobuf::EnumDescriptor* WorkingTimeInterval_Day_descriptor() {
  ::google::protobuf::internal::AssignDescriptors(&assign_descriptors_table_working_5ftime_2eproto);
  return file_level_enum_descriptors_working_5ftime_2eproto[0];
}
bool WorkingTimeInterval_Day_IsValid(int value) {
  switch (value) {
    case 0:
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
    case 6:
    case 7:
      return true;
    default:
      return false;
  }
}

#if !defined(_MSC_VER) || _MSC_VER >= 1900
const WorkingTimeInterval_Day WorkingTimeInterval::EVERYDAY;
const WorkingTimeInterval_Day WorkingTimeInterval::MONDAY;
const WorkingTimeInterval_Day WorkingTimeInterval::TUESDAY;
const WorkingTimeInterval_Day WorkingTimeInterval::WEDNESDAY;
const WorkingTimeInterval_Day WorkingTimeInterval::THURSDAY;
const WorkingTimeInterval_Day WorkingTimeInterval::FRIDAY;
const WorkingTimeInterval_Day WorkingTimeInterval::SATURDAY;
const WorkingTimeInterval_Day WorkingTimeInterval::SUNDAY;
const WorkingTimeInterval_Day WorkingTimeInterval::Day_MIN;
const WorkingTimeInterval_Day WorkingTimeInterval::Day_MAX;
const int WorkingTimeInterval::Day_ARRAYSIZE;
#endif  // !defined(_MSC_VER) || _MSC_VER >= 1900

// ===================================================================

void WorkingTimeInterval::InitAsDefaultInstance() {
}
class WorkingTimeInterval::HasBitSetters {
 public:
};

#if !defined(_MSC_VER) || _MSC_VER >= 1900
const int WorkingTimeInterval::kDayFieldNumber;
const int WorkingTimeInterval::kMinutesFromFieldNumber;
const int WorkingTimeInterval::kMinutesToFieldNumber;
#endif  // !defined(_MSC_VER) || _MSC_VER >= 1900

WorkingTimeInterval::WorkingTimeInterval()
  : ::google::protobuf::Message(), _internal_metadata_(nullptr) {
  SharedCtor();
  // @@protoc_insertion_point(constructor:YellowPages.WorkingTimeInterval)
}
WorkingTimeInterval::WorkingTimeInterval(const WorkingTimeInterval& from)
  : ::google::protobuf::Message(),
      _internal_metadata_(nullptr) {
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  ::memcpy(&day_, &from.day_,
    static_cast<size_t>(reinterpret_cast<char*>(&minutes_to_) -
    reinterpret_cast<char*>(&day_)) + sizeof(minutes_to_));
  // @@protoc_insertion_point(copy_constructor:YellowPages.WorkingTimeInterval)
}

void WorkingTimeInterval::SharedCtor() {
  ::memset(&day_, 0, static_cast<size_t>(
      reinterpret_cast<char*>(&minutes_to_) -
      reinterpret_cast<char*>(&day_)) + sizeof(minutes_to_));
}

WorkingTimeInterval::~WorkingTimeInterval() {
  // @@protoc_insertion_point(destructor:YellowPages.WorkingTimeInterval)
  SharedDtor();
}

void WorkingTimeInterval::SharedDtor() {
}

void WorkingTimeInterval::SetCachedSize(int size) const {
  _cached_size_.Set(size);
}
const WorkingTimeInterval& WorkingTimeInterval::default_instance() {
  ::google::protobuf::internal::InitSCC(&::scc_info_WorkingTimeInterval_working_5ftime_2eproto.base);
  return *internal_default_instance();
}


void WorkingTimeInterval::Clear() {
// @@protoc_insertion_point(message_clear_start:YellowPages.WorkingTimeInterval)
  ::google::protobuf::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  ::memset(&day_, 0, static_cast<size_t>(
      reinterpret_cast<char*>(&minutes_to_) -
      reinterpret_cast<char*>(&day_)) + sizeof(minutes_to_));
  _internal_metadata_.Clear();
}

#if GOOGLE_PROTOBUF_ENABLE_EXPERIMENTAL_PARSER
const char* WorkingTimeInterval::_InternalParse(const char* begin, const char* end, void* object,
                  ::google::protobuf::internal::ParseContext* ctx) {
  auto msg = static_cast<WorkingTimeInterval*>(object);
  ::google::protobuf::int32 size; (void)size;
  int depth; (void)depth;
  ::google::protobuf::uint32 tag;
  ::google::protobuf::internal::ParseFunc parser_till_end; (void)parser_till_end;
  auto ptr = begin;
  while (ptr < end) {
    ptr = ::google::protobuf::io::Parse32(ptr, &tag);
    GOOGLE_PROTOBUF_PARSER_ASSERT(ptr);
    switch (tag >> 3) {
      // .YellowPages.WorkingTimeInterval.Day day = 1;
      case 1: {
        if (static_cast<::google::protobuf::uint8>(tag) != 8) goto handle_unusual;
        ::google::protobuf::uint64 val = ::google::protobuf::internal::ReadVarint(&ptr);
        msg->set_day(static_cast<::YellowPages::WorkingTimeInterval_Day>(val));
        GOOGLE_PROTOBUF_PARSER_ASSERT(ptr);
        break;
      }
      // int32 minutes_from = 2;
      case 2: {
        if (static_cast<::google::protobuf::uint8>(tag) != 16) goto handle_unusual;
        msg->set_minutes_from(::google::protobuf::internal::ReadVarint(&ptr));
        GOOGLE_PROTOBUF_PARSER_ASSERT(ptr);
        break;
      }
      // int32 minutes_to = 3;
      case 3: {
        if (static_cast<::google::protobuf::uint8>(tag) != 24) goto handle_unusual;
        msg->set_minutes_to(::google::protobuf::internal::ReadVarint(&ptr));
        GOOGLE_PROTOBUF_PARSER_ASSERT(ptr);
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
}
#else  // GOOGLE_PROTOBUF_ENABLE_EXPERIMENTAL_PARSER
bool WorkingTimeInterval::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!PROTOBUF_PREDICT_TRUE(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:YellowPages.WorkingTimeInterval)
  for (;;) {
    ::std::pair<::google::protobuf::uint32, bool> p = input->ReadTagWithCutoffNoLastTag(127u);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // .YellowPages.WorkingTimeInterval.Day day = 1;
      case 1: {
        if (static_cast< ::google::protobuf::uint8>(tag) == (8 & 0xFF)) {
          int value = 0;
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   int, ::google::protobuf::internal::WireFormatLite::TYPE_ENUM>(
                 input, &value)));
          set_day(static_cast< ::YellowPages::WorkingTimeInterval_Day >(value));
        } else {
          goto handle_unusual;
        }
        break;
      }

      // int32 minutes_from = 2;
      case 2: {
        if (static_cast< ::google::protobuf::uint8>(tag) == (16 & 0xFF)) {

          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::int32, ::google::protobuf::internal::WireFormatLite::TYPE_INT32>(
                 input, &minutes_from_)));
        } else {
          goto handle_unusual;
        }
        break;
      }

      // int32 minutes_to = 3;
      case 3: {
        if (static_cast< ::google::protobuf::uint8>(tag) == (24 & 0xFF)) {

          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::int32, ::google::protobuf::internal::WireFormatLite::TYPE_INT32>(
                 input, &minutes_to_)));
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
  // @@protoc_insertion_point(parse_success:YellowPages.WorkingTimeInterval)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:YellowPages.WorkingTimeInterval)
  return false;
#undef DO_
}
#endif  // GOOGLE_PROTOBUF_ENABLE_EXPERIMENTAL_PARSER

void WorkingTimeInterval::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:YellowPages.WorkingTimeInterval)
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  // .YellowPages.WorkingTimeInterval.Day day = 1;
  if (this->day() != 0) {
    ::google::protobuf::internal::WireFormatLite::WriteEnum(
      1, this->day(), output);
  }

  // int32 minutes_from = 2;
  if (this->minutes_from() != 0) {
    ::google::protobuf::internal::WireFormatLite::WriteInt32(2, this->minutes_from(), output);
  }

  // int32 minutes_to = 3;
  if (this->minutes_to() != 0) {
    ::google::protobuf::internal::WireFormatLite::WriteInt32(3, this->minutes_to(), output);
  }

  if (_internal_metadata_.have_unknown_fields()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        _internal_metadata_.unknown_fields(), output);
  }
  // @@protoc_insertion_point(serialize_end:YellowPages.WorkingTimeInterval)
}

::google::protobuf::uint8* WorkingTimeInterval::InternalSerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // @@protoc_insertion_point(serialize_to_array_start:YellowPages.WorkingTimeInterval)
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  // .YellowPages.WorkingTimeInterval.Day day = 1;
  if (this->day() != 0) {
    target = ::google::protobuf::internal::WireFormatLite::WriteEnumToArray(
      1, this->day(), target);
  }

  // int32 minutes_from = 2;
  if (this->minutes_from() != 0) {
    target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(2, this->minutes_from(), target);
  }

  // int32 minutes_to = 3;
  if (this->minutes_to() != 0) {
    target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(3, this->minutes_to(), target);
  }

  if (_internal_metadata_.have_unknown_fields()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields(), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:YellowPages.WorkingTimeInterval)
  return target;
}

size_t WorkingTimeInterval::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:YellowPages.WorkingTimeInterval)
  size_t total_size = 0;

  if (_internal_metadata_.have_unknown_fields()) {
    total_size +=
      ::google::protobuf::internal::WireFormat::ComputeUnknownFieldsSize(
        _internal_metadata_.unknown_fields());
  }
  ::google::protobuf::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  // .YellowPages.WorkingTimeInterval.Day day = 1;
  if (this->day() != 0) {
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::EnumSize(this->day());
  }

  // int32 minutes_from = 2;
  if (this->minutes_from() != 0) {
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::Int32Size(
        this->minutes_from());
  }

  // int32 minutes_to = 3;
  if (this->minutes_to() != 0) {
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::Int32Size(
        this->minutes_to());
  }

  int cached_size = ::google::protobuf::internal::ToCachedSize(total_size);
  SetCachedSize(cached_size);
  return total_size;
}

void WorkingTimeInterval::MergeFrom(const ::google::protobuf::Message& from) {
// @@protoc_insertion_point(generalized_merge_from_start:YellowPages.WorkingTimeInterval)
  GOOGLE_DCHECK_NE(&from, this);
  const WorkingTimeInterval* source =
      ::google::protobuf::DynamicCastToGenerated<WorkingTimeInterval>(
          &from);
  if (source == nullptr) {
  // @@protoc_insertion_point(generalized_merge_from_cast_fail:YellowPages.WorkingTimeInterval)
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
  // @@protoc_insertion_point(generalized_merge_from_cast_success:YellowPages.WorkingTimeInterval)
    MergeFrom(*source);
  }
}

void WorkingTimeInterval::MergeFrom(const WorkingTimeInterval& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:YellowPages.WorkingTimeInterval)
  GOOGLE_DCHECK_NE(&from, this);
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  if (from.day() != 0) {
    set_day(from.day());
  }
  if (from.minutes_from() != 0) {
    set_minutes_from(from.minutes_from());
  }
  if (from.minutes_to() != 0) {
    set_minutes_to(from.minutes_to());
  }
}

void WorkingTimeInterval::CopyFrom(const ::google::protobuf::Message& from) {
// @@protoc_insertion_point(generalized_copy_from_start:YellowPages.WorkingTimeInterval)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void WorkingTimeInterval::CopyFrom(const WorkingTimeInterval& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:YellowPages.WorkingTimeInterval)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool WorkingTimeInterval::IsInitialized() const {
  return true;
}

void WorkingTimeInterval::Swap(WorkingTimeInterval* other) {
  if (other == this) return;
  InternalSwap(other);
}
void WorkingTimeInterval::InternalSwap(WorkingTimeInterval* other) {
  using std::swap;
  _internal_metadata_.Swap(&other->_internal_metadata_);
  swap(day_, other->day_);
  swap(minutes_from_, other->minutes_from_);
  swap(minutes_to_, other->minutes_to_);
}

::google::protobuf::Metadata WorkingTimeInterval::GetMetadata() const {
  ::google::protobuf::internal::AssignDescriptors(&::assign_descriptors_table_working_5ftime_2eproto);
  return ::file_level_metadata_working_5ftime_2eproto[kIndexInFileMessages];
}


// ===================================================================

void WorkingTime::InitAsDefaultInstance() {
}
class WorkingTime::HasBitSetters {
 public:
};

#if !defined(_MSC_VER) || _MSC_VER >= 1900
const int WorkingTime::kFormattedFieldNumber;
const int WorkingTime::kIntervalsFieldNumber;
#endif  // !defined(_MSC_VER) || _MSC_VER >= 1900

WorkingTime::WorkingTime()
  : ::google::protobuf::Message(), _internal_metadata_(nullptr) {
  SharedCtor();
  // @@protoc_insertion_point(constructor:YellowPages.WorkingTime)
}
WorkingTime::WorkingTime(const WorkingTime& from)
  : ::google::protobuf::Message(),
      _internal_metadata_(nullptr),
      intervals_(from.intervals_) {
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  formatted_.UnsafeSetDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  if (from.formatted().size() > 0) {
    formatted_.AssignWithDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), from.formatted_);
  }
  // @@protoc_insertion_point(copy_constructor:YellowPages.WorkingTime)
}

void WorkingTime::SharedCtor() {
  ::google::protobuf::internal::InitSCC(
      &scc_info_WorkingTime_working_5ftime_2eproto.base);
  formatted_.UnsafeSetDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}

WorkingTime::~WorkingTime() {
  // @@protoc_insertion_point(destructor:YellowPages.WorkingTime)
  SharedDtor();
}

void WorkingTime::SharedDtor() {
  formatted_.DestroyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}

void WorkingTime::SetCachedSize(int size) const {
  _cached_size_.Set(size);
}
const WorkingTime& WorkingTime::default_instance() {
  ::google::protobuf::internal::InitSCC(&::scc_info_WorkingTime_working_5ftime_2eproto.base);
  return *internal_default_instance();
}


void WorkingTime::Clear() {
// @@protoc_insertion_point(message_clear_start:YellowPages.WorkingTime)
  ::google::protobuf::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  intervals_.Clear();
  formatted_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  _internal_metadata_.Clear();
}

#if GOOGLE_PROTOBUF_ENABLE_EXPERIMENTAL_PARSER
const char* WorkingTime::_InternalParse(const char* begin, const char* end, void* object,
                  ::google::protobuf::internal::ParseContext* ctx) {
  auto msg = static_cast<WorkingTime*>(object);
  ::google::protobuf::int32 size; (void)size;
  int depth; (void)depth;
  ::google::protobuf::uint32 tag;
  ::google::protobuf::internal::ParseFunc parser_till_end; (void)parser_till_end;
  auto ptr = begin;
  while (ptr < end) {
    ptr = ::google::protobuf::io::Parse32(ptr, &tag);
    GOOGLE_PROTOBUF_PARSER_ASSERT(ptr);
    switch (tag >> 3) {
      // string formatted = 1;
      case 1: {
        if (static_cast<::google::protobuf::uint8>(tag) != 10) goto handle_unusual;
        ptr = ::google::protobuf::io::ReadSize(ptr, &size);
        GOOGLE_PROTOBUF_PARSER_ASSERT(ptr);
        ctx->extra_parse_data().SetFieldName("YellowPages.WorkingTime.formatted");
        object = msg->mutable_formatted();
        if (size > end - ptr + ::google::protobuf::internal::ParseContext::kSlopBytes) {
          parser_till_end = ::google::protobuf::internal::GreedyStringParserUTF8;
          goto string_till_end;
        }
        GOOGLE_PROTOBUF_PARSER_ASSERT(::google::protobuf::internal::StringCheckUTF8(ptr, size, ctx));
        ::google::protobuf::internal::InlineGreedyStringParser(object, ptr, size, ctx);
        ptr += size;
        break;
      }
      // repeated .YellowPages.WorkingTimeInterval intervals = 2;
      case 2: {
        if (static_cast<::google::protobuf::uint8>(tag) != 18) goto handle_unusual;
        do {
          ptr = ::google::protobuf::io::ReadSize(ptr, &size);
          GOOGLE_PROTOBUF_PARSER_ASSERT(ptr);
          parser_till_end = ::YellowPages::WorkingTimeInterval::_InternalParse;
          object = msg->add_intervals();
          if (size > end - ptr) goto len_delim_till_end;
          ptr += size;
          GOOGLE_PROTOBUF_PARSER_ASSERT(ctx->ParseExactRange(
              {parser_till_end, object}, ptr - size, ptr));
          if (ptr >= end) break;
        } while ((::google::protobuf::io::UnalignedLoad<::google::protobuf::uint64>(ptr) & 255) == 18 && (ptr += 1));
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
bool WorkingTime::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!PROTOBUF_PREDICT_TRUE(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:YellowPages.WorkingTime)
  for (;;) {
    ::std::pair<::google::protobuf::uint32, bool> p = input->ReadTagWithCutoffNoLastTag(127u);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // string formatted = 1;
      case 1: {
        if (static_cast< ::google::protobuf::uint8>(tag) == (10 & 0xFF)) {
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_formatted()));
          DO_(::google::protobuf::internal::WireFormatLite::VerifyUtf8String(
            this->formatted().data(), static_cast<int>(this->formatted().length()),
            ::google::protobuf::internal::WireFormatLite::PARSE,
            "YellowPages.WorkingTime.formatted"));
        } else {
          goto handle_unusual;
        }
        break;
      }

      // repeated .YellowPages.WorkingTimeInterval intervals = 2;
      case 2: {
        if (static_cast< ::google::protobuf::uint8>(tag) == (18 & 0xFF)) {
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessage(
                input, add_intervals()));
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
  // @@protoc_insertion_point(parse_success:YellowPages.WorkingTime)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:YellowPages.WorkingTime)
  return false;
#undef DO_
}
#endif  // GOOGLE_PROTOBUF_ENABLE_EXPERIMENTAL_PARSER

void WorkingTime::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:YellowPages.WorkingTime)
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  // string formatted = 1;
  if (this->formatted().size() > 0) {
    ::google::protobuf::internal::WireFormatLite::VerifyUtf8String(
      this->formatted().data(), static_cast<int>(this->formatted().length()),
      ::google::protobuf::internal::WireFormatLite::SERIALIZE,
      "YellowPages.WorkingTime.formatted");
    ::google::protobuf::internal::WireFormatLite::WriteStringMaybeAliased(
      1, this->formatted(), output);
  }

  // repeated .YellowPages.WorkingTimeInterval intervals = 2;
  for (unsigned int i = 0,
      n = static_cast<unsigned int>(this->intervals_size()); i < n; i++) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      2,
      this->intervals(static_cast<int>(i)),
      output);
  }

  if (_internal_metadata_.have_unknown_fields()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        _internal_metadata_.unknown_fields(), output);
  }
  // @@protoc_insertion_point(serialize_end:YellowPages.WorkingTime)
}

::google::protobuf::uint8* WorkingTime::InternalSerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // @@protoc_insertion_point(serialize_to_array_start:YellowPages.WorkingTime)
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  // string formatted = 1;
  if (this->formatted().size() > 0) {
    ::google::protobuf::internal::WireFormatLite::VerifyUtf8String(
      this->formatted().data(), static_cast<int>(this->formatted().length()),
      ::google::protobuf::internal::WireFormatLite::SERIALIZE,
      "YellowPages.WorkingTime.formatted");
    target =
      ::google::protobuf::internal::WireFormatLite::WriteStringToArray(
        1, this->formatted(), target);
  }

  // repeated .YellowPages.WorkingTimeInterval intervals = 2;
  for (unsigned int i = 0,
      n = static_cast<unsigned int>(this->intervals_size()); i < n; i++) {
    target = ::google::protobuf::internal::WireFormatLite::
      InternalWriteMessageToArray(
        2, this->intervals(static_cast<int>(i)), target);
  }

  if (_internal_metadata_.have_unknown_fields()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields(), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:YellowPages.WorkingTime)
  return target;
}

size_t WorkingTime::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:YellowPages.WorkingTime)
  size_t total_size = 0;

  if (_internal_metadata_.have_unknown_fields()) {
    total_size +=
      ::google::protobuf::internal::WireFormat::ComputeUnknownFieldsSize(
        _internal_metadata_.unknown_fields());
  }
  ::google::protobuf::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  // repeated .YellowPages.WorkingTimeInterval intervals = 2;
  {
    unsigned int count = static_cast<unsigned int>(this->intervals_size());
    total_size += 1UL * count;
    for (unsigned int i = 0; i < count; i++) {
      total_size +=
        ::google::protobuf::internal::WireFormatLite::MessageSize(
          this->intervals(static_cast<int>(i)));
    }
  }

  // string formatted = 1;
  if (this->formatted().size() > 0) {
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::StringSize(
        this->formatted());
  }

  int cached_size = ::google::protobuf::internal::ToCachedSize(total_size);
  SetCachedSize(cached_size);
  return total_size;
}

void WorkingTime::MergeFrom(const ::google::protobuf::Message& from) {
// @@protoc_insertion_point(generalized_merge_from_start:YellowPages.WorkingTime)
  GOOGLE_DCHECK_NE(&from, this);
  const WorkingTime* source =
      ::google::protobuf::DynamicCastToGenerated<WorkingTime>(
          &from);
  if (source == nullptr) {
  // @@protoc_insertion_point(generalized_merge_from_cast_fail:YellowPages.WorkingTime)
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
  // @@protoc_insertion_point(generalized_merge_from_cast_success:YellowPages.WorkingTime)
    MergeFrom(*source);
  }
}

void WorkingTime::MergeFrom(const WorkingTime& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:YellowPages.WorkingTime)
  GOOGLE_DCHECK_NE(&from, this);
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  intervals_.MergeFrom(from.intervals_);
  if (from.formatted().size() > 0) {

    formatted_.AssignWithDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), from.formatted_);
  }
}

void WorkingTime::CopyFrom(const ::google::protobuf::Message& from) {
// @@protoc_insertion_point(generalized_copy_from_start:YellowPages.WorkingTime)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void WorkingTime::CopyFrom(const WorkingTime& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:YellowPages.WorkingTime)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool WorkingTime::IsInitialized() const {
  return true;
}

void WorkingTime::Swap(WorkingTime* other) {
  if (other == this) return;
  InternalSwap(other);
}
void WorkingTime::InternalSwap(WorkingTime* other) {
  using std::swap;
  _internal_metadata_.Swap(&other->_internal_metadata_);
  CastToBase(&intervals_)->InternalSwap(CastToBase(&other->intervals_));
  formatted_.Swap(&other->formatted_, &::google::protobuf::internal::GetEmptyStringAlreadyInited(),
    GetArenaNoVirtual());
}

::google::protobuf::Metadata WorkingTime::GetMetadata() const {
  ::google::protobuf::internal::AssignDescriptors(&::assign_descriptors_table_working_5ftime_2eproto);
  return ::file_level_metadata_working_5ftime_2eproto[kIndexInFileMessages];
}


// @@protoc_insertion_point(namespace_scope)
}  // namespace YellowPages
namespace google {
namespace protobuf {
template<> PROTOBUF_NOINLINE ::YellowPages::WorkingTimeInterval* Arena::CreateMaybeMessage< ::YellowPages::WorkingTimeInterval >(Arena* arena) {
  return Arena::CreateInternal< ::YellowPages::WorkingTimeInterval >(arena);
}
template<> PROTOBUF_NOINLINE ::YellowPages::WorkingTime* Arena::CreateMaybeMessage< ::YellowPages::WorkingTime >(Arena* arena) {
  return Arena::CreateInternal< ::YellowPages::WorkingTime >(arena);
}
}  // namespace protobuf
}  // namespace google

// @@protoc_insertion_point(global_scope)
#include <google/protobuf/port_undef.inc>