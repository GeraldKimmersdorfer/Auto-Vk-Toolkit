#pragma once

namespace cgb
{
	/** Sampler which is used to configure how to sample from an image. */
	class sampler_t
	{
	public:
		sampler_t() = default;
		sampler_t(const sampler_t&) = delete;
		sampler_t(sampler_t&&) = default;
		sampler_t& operator=(const sampler_t&) = delete;
		sampler_t& operator=(sampler_t&&) = default;
		~sampler_t() = default;

		const auto& config() const { return mInfo; }
		auto& config() { return mInfo; }
		const auto& handle() const { return mSampler.get(); }
		const auto& descriptor_info() const		{ return mDescriptorInfo; }
		const auto& descriptor_type() const		{ return mDescriptorType; }

		/**	Create a new sampler with the given configuration parameters
		 *	@param	pFilterMode					Filtering strategy for the sampler to be created
		 *	@param	pBorderHandlingMode			Border handling strategy for the sampler to be created
		 *	@param	pAlterConfigBeforeCreation	A context-specific function which allows to alter the configuration before the sampler is created.
		 */
		static owning_resource<sampler_t> create(filter_mode pFilterMode, border_handling_mode pBorderHandlingMode, context_specific_function<void(sampler_t&)> pAlterConfigBeforeCreation = {});

	private:
		// Sampler creation configuration
		vk::SamplerCreateInfo mInfo;
		// Sampler handle. It will contain a valid handle only after successful sampler creation.
		vk::UniqueSampler mSampler;
		vk::DescriptorImageInfo mDescriptorInfo;
		vk::DescriptorType mDescriptorType;
		context_tracker<sampler_t> mTracker;
	};

	/** Typedef representing any kind of OWNING sampler representations. */
	using sampler = owning_resource<sampler_t>;

}
